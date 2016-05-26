#ifndef _QUEUES_H
#define _QUEUES_H

#include "Nodes.h"
#include "Stacks.h"

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_set>

using namespace std;

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

};

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

#endif