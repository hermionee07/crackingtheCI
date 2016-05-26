
#include "Nodes.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_set>

using namespace std;

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
