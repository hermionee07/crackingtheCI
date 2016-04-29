
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <unordered_set>
using namespace std;

bool IsUnique(const std::string& str)
{
    if (str.length() > 128) // Ascii 128 character.
        return false;
    bool chars[128] = {false};
    for (const char& c: str)
    {
        if (!chars[c])
        {
            chars[c] = true;
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool IsUniqueNoBuffer(const std::string &str)
{
    unsigned int buffer = 0;
    if (str.length() > 128)
        return false;
    for (const char& a: str)
    {
        unsigned int temp = 1 << (a - 97);
        unsigned int andResult = temp & buffer;
        if (andResult != temp) // not set
        {
            buffer = buffer | temp;
            continue;
        }
        else
            return false;
    }
    return true;
}

void stringReverse(char* str)
{  // to do it in place
    char* ptr = str;
    int length = 0;
    while(*ptr != '\0')
    {
        ptr++;
        length++;
    }
    for (int i = 0, j = length-1; i < length/2;)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

bool areAnagrams( string str1, string str2)
{  // uses std::sort
    if (str1.length() != str2.length())
        return false;
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    if (str1.compare(str2) == 0)
        return true;
    return false;
}

bool areAnagramsWithoutSort(const string& str1, const string& str2)
{
    if (str1.length() != str2.length())
        return false;
    map<char, int> charCountMap;
    for (const char&a : str1)
    {
        charCountMap[a] = charCountMap[a] + 1;
    }
    for (const char& a: str2)
    {
         charCountMap[a] = charCountMap[a] - 1;
         if (charCountMap[a] < 0)
            return false;
    }
    /*map<char,int>::const_iterator itr = charCountMap.begin();
    while (itr != charCountMap.end())
    {
        if (itr->second != 0)
            return false;
        itr++;
    }*/
    return true;
}


bool isCyclicSubstring(const string& str1, const string& str2)
{ // we can use substr to find this.
    string cStr1 = str1;
    string cStr2 = str2;
    if (str1.length() != str2.length())
        return false;
    string temp = "";
    for (const char& a: str2)
    {
        temp = temp + a;
        if (strstr(cStr1.c_str(), temp.c_str()) == NULL)
        {
            break;
        }
    }
    string partString = cStr2.erase(0, temp.length());
    if (strstr(str1.c_str(), partString.c_str()) == NULL)
        return false;
    else
        return true;
}

void URLify(char* str)
{ // do it inplace and think there is sufficient space at the end
    char* ptr = str;
    int length = 0, noOfSpaces = 0;
    while (*ptr != '\0')
    {
        length++;
        if (*ptr == ' ')
            noOfSpaces++;
        ptr++;
    }
    int finalLength = length + 2 * noOfSpaces;
    str[finalLength] = '\0';
    for (int i = 1, j = 1; i <= finalLength;)
    {
        if (str[length-j] == ' ')
        {
            str[finalLength-i] = '0';
            str[finalLength-i-1] = '2';
            str[finalLength-i-2] = '%';
            i+=3;
            j++;
        }
        else
        {
            str[finalLength-i] = str[length-j];
            j++;
            i++;
        }
    }
}

class Node
{
    public:
        Node* _next;
        int _data;
        ~Node()
        {
       //     cout << "deleting " << _data <<endl;
        }

        Node(int a) : _data(a) { _next = nullptr;}

        void appendToTail(int a)
        {
            Node* newNode = new Node(a);
            Node* head = this;
            while(head->_next != nullptr)
            {
                head = head->_next;
            }
            head->_next = newNode;
        }

        Node* deleteData(int a)
        {// this one is WRONG!
            Node* head = this;
            Node* curr = head;
            Node* prev = nullptr;
            while (curr != nullptr)
            {
                if (curr->_data == a && curr == head)
                {
                    Node* temp = head->_next;
            ;        delete head;
                    return temp;
                }
                else if (curr->_data == a)
                {
                    prev->_next = curr->_next;
                    delete curr;
                    break;
                }
                else
                {
                    prev = curr;
                    curr = curr->_next;
                }

            }
            return head;
        }
};

void DeleteData(Node** head, int a)
{
    Node* curr = *head;
    Node* prev = nullptr;
    while (curr != nullptr)
    {
        if (curr->_data == a && prev == nullptr)
        {
            *head = curr->_next;
            delete curr;
            return;
        }
        else if (curr->_data == a)
        {
            prev->_next = curr->_next;
            delete curr;
            return;
        }
        prev = curr;
        curr = prev->_next;
    }

}

void printLL(Node* head)
{
    Node* curr = head;
    if (curr == nullptr)
        return;
    while (curr != nullptr)
    {
        cout << curr->_data << "-->";
        curr = curr->_next;
    }
}

void deleteLL(Node** head)
{
    while(*head != nullptr)
    {
        Node* temp = (*head)->_next;
        *head = temp;
        delete *head;
    }
}

void deleteDups(Node** head)
{ // uses a buffer
   unordered_set<int> mySet;

    Node* curr = *head;
    Node* prev = nullptr;
    while (curr != nullptr)
    {
        if (mySet.find(curr->_data) == mySet.end())
        {
            cout << "inserting ... " << curr->_data << endl;
            mySet.insert(curr->_data);
        }
        else
        {
            Node* temp = curr;
            prev->_next = curr->_next;
            curr = curr->_next;
            delete temp;
            continue;
        }
        prev = curr;
        curr = prev->_next;
    }
}

void deleteDupsNoBuffer(Node** head)
{ // no buffer
    Node* curr = *head;
    Node* runn = *head;
    Node* prev = nullptr;
    while (curr != nullptr)
    {
        while (runn != curr)
        {
            cout << "coming here .." << endl;
            if (runn->_data == curr->_data)
            {
                cout << "found a match .. " << endl;
                Node* temp2 = runn;
                if (prev == nullptr)
                {
                    *head = runn->_next;
                    runn = runn->_next;
                }
                else
                {
                    prev->_next = runn->_next;
                    runn = runn->_next;
                }
                cout << "deleting ... "<< temp2->_data;
                delete temp2;
                continue;
            }
            prev = runn;
            runn = prev->_next;
        }
        runn = *head;
        prev = nullptr;
        curr = curr->_next;
    }
}



int findKthFromLastii(const Node* head, int k)
{//naive solution
    int length = 0;
    const Node* temp = head;
    while (temp != nullptr)
    {
        length+=1;
        temp = temp->_next;
    }
    cout << "lenght ... " << length << endl;
    temp = head;
    int count = 0;
    while (temp!= nullptr)
    {
        count += 1;
        cout << "count is .. " << count << endl;
        if (length - count == k)
            return temp->_data;
        temp = temp->_next;
    }
    return 0;
}


int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n -1);
}


Node* findKthFromLast(Node* head, int k, int& a)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    else
    {
        Node* ret = findKthFromLast(head->_next, k, a);
        a = a+1;
        if (a == k)
            return head;
        return ret;
    }
}


Node* findKth(Node* head, int k)
{
    int i = 0;
    return findKthFromLast(head->_next, k, i);
}


Node* findKth2(Node* head, int k)
{
    Node* temp1 = head;
    Node* temp2 = head;
    int count = 0;
    while (count != k)
    {
        Node* temp = temp1;
        temp1 = temp->_next;
        count++;
    }
    while (temp2->_next == nullptr)
    {
        Node* a = temp1;
        temp1 = a->_next;
        a = temp2;
        temp2 = a->_next;
    }
    return temp1;
}

void foo(int *a)
{
    *a = 1;
    cout << a<< " " <<*a <<endl;
    a = nullptr;
    cout << a << " ..." <<endl;
}

Node* add(Node* first, Node* sec)
{
    Node* res = new Node(0);
    Node* head = res;
    int carry = 0;
    int val = 0;
    int result = 0;
    printLL(first);
    cout <<"...................................."<<endl;
    printLL(sec);
    while (first != nullptr || sec != nullptr)
    {
        cout << first->_data << " + " << sec->_data <<endl;
        cout << carry << endl;
        val = (first->_data + sec->_data + res->_data);
        if ( val >= 10)
        {
            carry =  val / 10;
            result = val % 10;
        }
        else
        {
            carry = 0;
            result = val;
        }
        res->_data = result ;
        res->_next = new Node(carry);
        cout << res->_data << endl;
        Node* temp = res;
        res = temp->_next;
        temp = first;
        first = temp->_next;
        temp = sec;
        sec = temp->_next;
    }
    printLL(head);
    cout << "................." << endl;
    return head;
}

bool findCycleInLL(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while (slow != nullptr)
    {
        cout << slow->_data << " slow" << endl;
        cout << fast->_data << " fast" << endl;
        Node* temp = slow;
        slow = temp->_next;
        temp = fast;
        fast = temp->_next->_next != nullptr ? temp->_next->_next: nullptr;
        if (fast == nullptr)
        {
            return false;
        }
        else if (slow == fast)
        {
            cout << slow->_data << " " << fast->_data <<endl;
            return true;
        }
    }
}

int findNumNodesInCycleLL(Node* head)
{
    if (!findCycleInLL(head))
    {
        return 0;
    }
    Node* slow = head;
    Node* fast = head;
    int count = 0;
    while (slow != nullptr)
    {
        cout << slow->_data << " slow" << endl;
        cout << fast->_data << " fast" << endl;
        Node* temp = slow;
        slow = temp->_next;
        temp = fast;
        fast = temp->_next->_next;
        if (slow == fast)
        {
            cout << slow->_data << " " << fast->_data <<endl;
            if (count)
                return count;
            count++;
            continue;
        }
        if (count)
            count++;
    }

}

Node* findStartOfCycleLL(Node *head)
{
    int a = findNumNodesInCycleLL(head);
    if (a == 0)
        return nullptr;
    Node* itr1 = head;
    Node* itr2 = head;
    while (a != 0)
    {
        Node* temp = itr2;
        itr2 = temp->_next;
        a--;
    }
    cout << itr1->_data << "....." << itr2->_data << endl;
    while (itr2 != itr1)
    {
        Node* temp = itr1;
        itr1 = temp->_next;
        temp = itr2;
        itr2 = temp->_next;
    }

    return itr1;
}

void partitionLL(Node* head, int a)
{
    if (head == nullptr)
        return ;//nullptr;
    Node* leftItr = nullptr;
    Node* rightItr = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* curr = head;
    while (curr != nullptr)
    {
        if (curr->_data < a)
        {
            Node* temp = curr;
            cout << curr->_data <<" less " <<endl;
            curr = temp->_next;
            if (left == nullptr)
            {
                left = temp;
                leftItr = temp;
            }
            else
            {
                leftItr->_next = temp;
                leftItr = temp;
            }
            leftItr->_next = nullptr;
            cout << "left... " << endl;
            printLL(left);
            cout <<" ............................." <<endl;

            cout << leftItr->_data << ".........leftItr is " << endl;
        }
        else
        {
            Node* temp = curr;
            cout << curr->_data<<" more "<< endl;
            curr = temp->_next;
            if (right == nullptr)
            {
                right = temp;
                rightItr = temp;
            }
            else
            {
                rightItr->_next = temp;
                rightItr = temp;
            }
            rightItr->_next = nullptr;
            cout << "right... " << endl;
            printLL(right);
            cout <<" ............................." <<endl;

            cout << rightItr->_data << ".........rightItr is " << endl;

        }
    }
    leftItr->_next = right;
    printLL(left);
    //return left;
}

Node* checkIntersection(Node* head1, Node* head2)
{
    //k is the legnth of common nodes.
    //x is lenght of head1, y is lenght of head2
    //k common nodes will be at the end.
    Node* curr1 = head1;
    Node* curr2 = head2;
    int length1 = 0, length2 = 0;
    while(curr1 != nullptr)
    {
        curr1 = curr1->_next;
        length1++;
    }
    while(curr2 != nullptr)
    {
        curr2 = curr2->_next;
        length2++;
    }
    cout <<"...." <<length1 << " " << length2 << endl;
    int moveAhead = 0;
    bool secLonger = false;
    if (length1 - length2 < 0)
    {
        moveAhead = length2 - length1;
        secLonger = true;
    }
    else
    {
        moveAhead = length1 - length2;
    }

    while (moveAhead)
    {
        if (secLonger)
        {
            head2 = head2->_next;
        }
        else
        {
            head1 = head1->_next;
        }
        moveAhead--;
    }

    while (head1 != nullptr || head2 != nullptr)
    {
        if (head1 == head2)
        {
            cout << head1->_data << "found it" <<endl;
            return head1;
        }
        else
        {
            head1 = head1->_next;
            head2 = head2->_next;
        }
    }
    return nullptr;
}

class Stack
{
    private:
        Node* head;
        Node* minUptoHead;

    public:
        void push(int a)
        {
            Node* newNode = new Node(a);
            newNode->_next = head;
            head = newNode;
            if (minUptoHead == nullptr)
            {
                minUptoHead = new Node(a);
                minUptoHead->_next = nullptr;
            }
            else
            {
                if (minUptoHead->_data >= a)
                {
                    Node* temp = new Node(a);
                    temp->_next = minUptoHead;;
                    minUptoHead = temp;
                }
            }
        }

        int min() // min in the stack
        {
            if (minUptoHead != nullptr)
                return minUptoHead->_data;
            else
                return -1;
        }

        int pop()
        {
            int retVal = 0;
            if (head != nullptr)
            {
                retVal = head->_data;
                Node* temp = head->_next;
                delete head;
                head = temp;
                if (minUptoHead != nullptr && retVal == minUptoHead->_data)
                {
                    Node* temp = minUptoHead;
                    minUptoHead = temp->_next;
                    delete temp;
                }
                return retVal;
            }
            else
                return -1; // need to have exception handling for errors.
        }
        void PrintStack()
        {
            Node* temp = head;
            while(temp != nullptr)
            {
                cout << temp->_data << "<--";
                temp = temp->_next;
            }
        }
        Stack(): head(nullptr), minUptoHead(nullptr) {}
        ~Stack()
        {
            while (head != nullptr)
            {
                Node* temp = head;
                head = temp->_next;
                delete temp;
            }
            while (minUptoHead != nullptr)
            {
                Node* temp = minUptoHead;
                minUptoHead = temp->_next;
                delete temp;
            }
        }
};

class SStack
{
    private:
        Node* head;

    public:
        void push(int a)
        {
            Node* newNode = new Node(a);
            newNode->_next = head;
            head = newNode;
        }

        int pop()
        {
            int retVal = 0;
            if (head != nullptr)
            {
                retVal = head->_data;
                Node* temp = head->_next;
                delete head;
                head = temp;
                return retVal;
            }
            else
                return -1; // need to have exception handling for errors.
        }
        int peek()
        {
            if (head != nullptr)
                return head->_data;
            else
                return -1;
        }

        void printStack()
        {
            Node* temp = head;
            while(temp != nullptr)
            {
                cout << temp->_data << "<--";
                temp = temp->_next;
            }
        }

        SStack(): head(nullptr) {}

        ~SStack()
        {
            while (head != nullptr)
            {
                Node* temp = head;
                head = temp->_next;
                delete temp;
            }
        }
        bool empty()
        {
            if (head != nullptr)
                return false;
            return true;
        }

};

// Towers of hanoi using stacks
// first tower with arranged assendingly
// second is free, need to move from first to third.
// (A) Only one disk can be moved at a time.
// (B) A disk is slid off the top of one rod onto the next rod.
// (C) A disk can only be placed on top of a larger disk.
void hanoiUp(SStack& source, SStack& aux, SStack& dest)
{
    //if(tower1.empty())
    //    return;
    // So I am not going to do this now.
}

// can use additional stack but no other data structure;
void sortAStack(SStack& a)
{
    SStack buffer;
    while(!a.empty())
    {
        if (buffer.empty())
        {
            buffer.push(a.pop());
            buffer.printStack();
            cout << "<<<<<<<<<<<<<" <<endl;
            continue;
        }
        int temp;
        if (a.peek() > buffer.peek())
        {
            temp = a.pop();
            cout << "temp is " << temp << endl;
            cout << "buffer.peek() is " << buffer.peek() << endl;
            while(buffer.peek() < temp && !buffer.empty())
            {
                cout << "pushing " << buffer.peek() << " into a " << endl;
                a.push(buffer.pop());
                cout << "a is ";
                a.printStack();
                cout << endl;
            }
            buffer.push(temp);
            cout << "buffer is ";
            buffer.printStack();
            cout << "\n.................................\n";
            continue;
        }
        if (!buffer.empty() && a.peek() < buffer.peek())
        {
            buffer.push(a.pop());
            buffer.printStack();
            cout << "\n----------------------------------\n";
            cout << "a is " ;
            a.printStack();
            cout << endl;
            if (a.empty())
            {
                cout << "coming here" << endl;
                break;
            }
            continue;
        }

    }
   // buffer.printStack();

}

class Queue
{
    private:
        Node* first;
        Node* last;
    public:
        Queue() : first(nullptr), last(nullptr) {}
        ~Queue()
        {
            while(first != nullptr)
            {
                Node* temp = first;
                first = temp->_next != nullptr ? temp->_next : nullptr;
                delete temp;
            }
        }
        void enqueue(int a)
        {
            Node* newNode = new Node(a);
            if(last != nullptr)
            {
                last->_next = newNode;
            }
            last = newNode;
            if (first == nullptr)
                first = last;

        }

        int dequeue()
        {
            if (first == nullptr)
                return -1;
            else
            {
                Node* temp = first;
                first = temp->_next != nullptr ? temp->_next : nullptr;
                delete temp;
                return temp->_data;
            }
        }
        void printQueue()
        {
            Node* temp = first;
            while (temp != nullptr)
            {
                cout << temp->_data << "-->" ;
                temp = temp->_next;
            }
            cout << endl;
        }
        bool empty()
        {
            if (first != nullptr)
                return false;
            return true;
        }

;

// Make a queue with 2 stacks.
class MyQ
{
    private:
        SStack pushStack;
        SStack popStack;
    public:
        void enQ(int a)
        { // push it all on pushStack
            pushStack.push(a);
        }

        int deQ()
        {// pop all from the pushstack and put into the
         // popStack.
            if (popStack.empty())
            {
                while(!pushStack.empty())
                {
                    popStack.push(pushStack.pop());
                }
            }
            return popStack.pop();
        }

        void printQ()
        {
            popStack.printStack();
            pushStack.printStack();
        }

        MyQ() {}
        ~MyQ() {}
};

// Animal Shelter
class AnimalShelter
{
   // private:

};

int main()
{
    std::cout << "Enter the string: "<< std::endl;
   // std::string str;// = "tes";
    //std::getline(std::cin, str);
    //std::cout << IsUnique(str) << std::endl;
    //std::cout << IsUniqueNoBuffer(str) << std::endl;
    string test("blahss");
    char* test1 = (char*)test.c_str();
    //char* test = "teso";
    //std::size_t t = test.find(":");
    //std::size_t r = t == std::string::npos ? test.length(): t;
    //std::cout << test.substr(0, r);
    cout<< test1;
    stringReverse(test1);
    cout << test1;
    //std::cout << sizeof(long double);
    string blue ="blue";
    string u = "eubl";
    cout << areAnagramsWithoutSort(blue, u);
    char url[128] = " this is the world";
    cout << url;
    URLify(url);
    cout << url;

    string str1="waterbottle";
    string str2="lewaterbott";
    cout << isCyclicSubstring(str1, str2)<< endl;
    Node* head = new Node(10);
    head->appendToTail(15);
    head->appendToTail(21);
    head->appendToTail(25);
    head->appendToTail(26);
    head->appendToTail(27);
    head->appendToTail(10);
    head->appendToTail(10);
    printLL(head);
    cout << endl;
 //   Node* modi = head->deleteData(10);
 //   deleteDupsNoBuffer(&head);
    //DeleteData(&head, 10);
   // printLL(head);
    cout << endl;
  //  deleteLL(&head);
  //  printLL(head);
  //  int a = 10;
  //  foo(&a);
  //  cout << &a << " " << a <<endl;
   // cout << findKthFromLastii(head, 0)<< endl;
   // cout << fact(6) << endl;
   // Node* temp = findKth2(head, 0);
   // char as[8] = {'a','a','a','s','s','d','f', '\0'};
   // const char* ars ="test";
   // char ab[5] = {'a','a','a','s','s','\0'};
   // const char *a;
   // a ="hjklsdasdasdssdfsdfgsdgdfgdfgdgdgdhdhgfhfhfhfgfhf";
   // cout << ab<<"......." <<endl;
   // cout << std::string(ab)<<endl;;
    Node* head1 = new Node(1);
    Node* head2 = new Node(2);
    Node* head3 = new Node(3);
    Node* head4 = new Node(4);
    Node* head5 = new Node(5);
    Node* head6 = new Node(6);
    Node* head7 = new Node(7);
    Node* head8 = new Node(8);
    Node* head9 = new Node(9);
    Node* head10 = new Node(10);


    head1->_next = head2;
    head2->_next = head3;
    head3->_next = head4;
    head4->_next = head5;
    head5->_next = head6;
    head6->_next = head7;
     //cout << findCycleInLL(head1);
    head7->_next = head8;
    head8->_next = head9;
    head9->_next = head10;
    //head10->_next = head5;
    head10->_next = nullptr;
    cout << head1 << " head " <<endl;
    //cout << findCycleInLL(head1) << endl;
   // cout << findNumNodesInCycleLL(head1)<< endl;
    if (findStartOfCycleLL(head) == nullptr)
        cout << "no cycle exists!" << endl;
    else
        cout << findStartOfCycleLL(head)->_data << endl;
    // partitionLL(head, 25);
    printLL(head1);

    Node* heada1 = new Node(1);
    Node* heada2 = new Node(2);
    Node* heada3 = new Node(3);
    Node* heada4 = new Node(4);
    Node* heada5 = new Node(5);
    Node* heada6 = new Node(6);
    Node* heada7 = new Node(7);
    Node* heada8 = new Node(8);
    Node* heada9 = new Node(9);
    heada1->_next = heada2;
    heada2->_next = heada3;
    heada3->_next = heada4;
    heada4->_next = heada5;
    heada5->_next = heada6;
    heada6->_next = heada7;
    heada7->_next = heada8;
    heada8->_next = heada9;


    heada9->_next = nullptr;
     //cout << findCycleInLL(head1);
    //head10->_next = head5;


    checkIntersection(head1, heada1);
    //cout << head1 << " head2 " << endl;
    //printLL(result);
   // head1->appendToTail(5);

   // Node* head2 = new Node(5);
   // head2->appendToTail(5);
   // Node* res = add(head1, head2);
  //  printLL(res);
    int num = 0;
    string numstr = "";
    while(num != 128)
    {
      //  cout << char(num);
        numstr = numstr + char(num);
        num++;
    }

    /*Stack mystack;
    mystack.push(40);
    mystack.push(30);
    mystack.push(30);
    mystack.push(40);
    mystack.push(20);
    mystack.push(10);
    cout << "current min is " <<mystack.min() << endl;
    cout << mystack.pop() << "... poped" << endl;
    mystack.PrintStack();
    cout << "current min is " <<mystack.min() << endl;
    cout << mystack.pop() << "... poped" << endl;
    mystack.PrintStack();

    cout << "current min is " <<mystack.min()  << endl;
    Queue myqueue;
    myqueue.enqueue(10);
    myqueue.enqueue(20);
    myqueue.enqueue(30);
    myqueue.enqueue(40);
    myqueue.enqueue(50);
    myqueue.enqueue(60);
    myqueue.printQueue();
    cout << "dequeueed..." << myqueue.dequeue() << endl;
    myqueue.printQueue();*/
    MyQ myq;
    myq.enQ(10);
    //myq.enQ(20);
    //myq.enQ(30);
    //myq.enQ(40);
    //myq.enQ(50);
    myq.printQ();
    cout << myq.deQ() <<" deQed..." <<endl;
    myq.enQ(20);
    myq.printQ();
    cout << "\nthe stack is ..." ;
    SStack tower1;
    tower1.push(50);
    tower1.push(60);
    tower1.push(20);
    tower1.push(80);
    tower1.push(10);
    tower1.printStack();
    cout << "hello" <<endl;
    sortAStack(tower1);

   //cout << numstr;
    //cout << "Kth is ..." << temp->_data;
   return 0;
}
