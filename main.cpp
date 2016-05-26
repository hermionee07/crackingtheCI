#include "Nodes.h"
#include "Stacks.h"
#include "Queues.h"
#include "strings.h"


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
