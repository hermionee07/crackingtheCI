#ifndef _STACKS_H
#define _STACKS_H

#include "Nodes.h"

class Stack
{
    private:
        Node* head;
        Node* minUptoHead;

    public:
        void push(int a);
        
        int min(); // min in the stack
        
        int pop();
        
        void PrintStack();
        
        Stack(): head(nullptr), minUptoHead(nullptr) {}
        ~Stack(){
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
        void push(int a);
        
        int pop();
        
        int peek();
        
        void printStack();
        
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
        
        bool empty();
       
};

// Towers of hanoi using stacks
// first tower with arranged assendingly
// second is free, need to move from first to third.
// (A) Only one disk can be moved at a time.
// (B) A disk is slid off the top of one rod onto the next rod.
// (C) A disk can only be placed on top of a larger disk.
void hanoiUp(SStack& source, SStack& aux, SStack& dest);

// can use additional stack but no other data structure;
void sortAStack(SStack& a);

#endif