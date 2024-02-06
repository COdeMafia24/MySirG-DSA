#include<iostream>
#define EMPTY_DEQUE 1
using namespace std;

class Node
{
    public:
        Node *prev;
        int item;
        Node *next;
};
class Deque
{
    private:
        Node *front, *rear;
    public:
        Deque();
        void insertFront(int);
        void insertRear(int);
        void deleteFront();
        void deleteRear();
        int getFront();
        int getRear();
        ~Deque();
        bool isEmpty();
};
Deque::Deque()
{
    front=rear=nullptr;
}
void Deque::insertFront(int data)
{
    Node *n=new Node;
    n->prev=nullptr;
    n->item=data;
    n->next=front;
    if(front==nullptr)
    {
        front=n;
        rear=n;
    }
    else
    {
        front->prev=n;
        front=n;
    }
}
void Deque::insertRear(int data)
{
    Node *n=new Node;
    n->prev=rear;
    n->item=data;
    n->next=nullptr;
    if(rear==nullptr)
        front=rear=n;
    else
    {
        rear->next=n;
        rear=n;
    }
}
void Deque::deleteFront()
{
    Node *r;
    if(front)
    {
        if(front->next==nullptr)
        {
            delete front;
            front=rear=nullptr;
        }
        else
        {
            r=front;
            front=front->next;
            front->prev=nullptr;
            delete r;
        }
    }
}
void Deque::deleteRear()
{
    Node *r;
    if(rear)
    {
        if(rear->prev==nullptr)
        {
            delete rear;
            front=rear=nullptr;
        }
        else
        {
            r=rear;
            rear=rear->prev;
            rear->next=nullptr;
            delete r;
        }
    }
}
int Deque::getFront()
{
    if(front==nullptr)
        throw EMPTY_DEQUE;
    return front->item;
}
int Deque::getRear()
{
    if(rear==nullptr)
        throw EMPTY_DEQUE;
    return rear->item;
}
Deque::~Deque()
{
    while(front)
        deleteFront();
}
bool Deque::isEmpty()
{
    return front==nullptr;
}