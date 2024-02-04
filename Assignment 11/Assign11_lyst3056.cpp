#include<iostream>
using namespace std;
#define EMPTY_QUEUE 1
class Node
{
    public:
        int item;
        Node *next;
};
class Queue
{
    private:
        Node *front,*rear;
        int count;
    public:
        Queue();
        void enqueue(int);
        int getRear();
        int getFront();
        void dequeue();
        ~Queue();
        int countItems();
};
Queue::Queue()
{
    front=rear=nullptr;
    count=0;
}
void Queue::enqueue(int data)
{
    Node *n=new Node;
    n->item=data;
    n->next=nullptr;
    if(rear==nullptr)
        front=rear=n;
    else 
    {
        rear->next=n;
        rear=n;
    }
    count++;
}
int Queue::getFront()
{
    if(front==nullptr)
        throw EMPTY_QUEUE;
    return front->item;
}
int Queue::getRear()
{
    if(rear==nullptr)
        throw EMPTY_QUEUE;
    return rear->item;
}
void Queue::dequeue()
{
    Node *r;
    if(front!=nullptr)
    {
        r=front;
        if(front==rear)
            front=rear=nullptr;
        else
            front=front->next;
        delete r;
        count--;
    }
}
Queue::~Queue()
{
    while(front)
        dequeue();
}

int Queue::countItems()
{
    return count;
}