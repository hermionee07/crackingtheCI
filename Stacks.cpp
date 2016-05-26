
#include "Stacks.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_set>

using namespace std;

void Stack::push(int a)
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

int Stack::min() // min in the stack
{
    if (minUptoHead != nullptr)
        return minUptoHead->_data;
    else
        return -1;
}

int Stack::pop()
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
void Stack::PrintStack()
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->_data << "<--";
        temp = temp->_next;
    }
}


void SStack::push(int a)
{
    Node* newNode = new Node(a);
    newNode->_next = head;
    head = newNode;
}

int SStack::pop()
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
int SStack::peek()
{
    if (head != nullptr)
        return head->_data;
    else
        return -1;
}

void SStack::printStack()
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->_data << "<--";
        temp = temp->_next;
    }
}


bool SStack::empty()
{
    if (head != nullptr)
        return false;
    return true;
}


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
