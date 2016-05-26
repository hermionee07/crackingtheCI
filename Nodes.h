#ifndef _NODES_H_
#define _NODES_H_

using namespace std;

class Node
{
    public:
        Node* _next;
        int _data;
        ~Node()
        {
       //     cout << "deleting " << _data <<endl;
        }

        Node(int a) : _data(a) { _next = nullptr; }

        //void appendToTail(int a);
 
        //Node* deleteData(int a);
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
        {//this one is WRONG!
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

void DeleteData(Node** head, int a);


void printLL(Node* head);


void deleteLL(Node** head);


void deleteDups(Node** head);


void deleteDupsNoBuffer(Node** head);


int findKthFromLastii(const Node* head, int k);


int fact(int n);

Node* findKthFromLast(Node* head, int k, int& a);


Node* findKth(Node* head, int k);


Node* findKth2(Node* head, int k);


void foo(int *a);


Node* add(Node* first, Node* sec);


bool findCycleInLL(Node* head);


int findNumNodesInCycleLL(Node* head);


Node* findStartOfCycleLL(Node *head);


void partitionLL(Node* head, int a);


Node* checkIntersection(Node* head1, Node* head2);

#endif