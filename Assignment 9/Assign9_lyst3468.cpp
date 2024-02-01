#include<iostream>
using namespace std;
#define STACK_EMPTY 1
class Node
{
    public:
        int item;
        Node *next;
};
class Stack
{
    private:
        Node *top;
    public:
        Stack();
        void push(int);
        int peek();
        void pop();
        bool isEmpty();
        ~Stack();
};
Stack::Stack()
{
    top=nullptr;
}
void Stack::push(int data)
{
    Node *n=new Node;
    n->item=data;
    n->next=top;
    top=n;
}
int Stack::peek()
{
    if(top==nullptr)
        throw STACK_EMPTY;
    return top->item;
}
void Stack::pop()
{
    Node *r;
    if(top)
    {
        r=top;
        top=top->next;
        delete r;
    }
}
bool Stack::isEmpty()
{
    return top==nullptr;
}
Stack::~Stack()
{
    while(top)
        pop();
}
Stack * reverseStack(Stack *s)
{
    Stack *stkptr=new Stack();
    while(!(s->isEmpty()))
    {
        stkptr->push(s->peek());
    }
    return stkptr;
}
