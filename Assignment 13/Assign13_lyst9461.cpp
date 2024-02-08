#include<iostream>
#define EMPTY_PRIORITY_QUEUE 1
using namespace std;
class Node
{
    public:
        int item;
        int pno;
        Node *next;
};
class PriorityQueue
{
    private:
        Node *start;
    public:
        PriorityQueue();
        void insert(int,int);
        void deleteItem();
        bool isEmpty();
        int getHighestPriorityItem();
        int getHighestPriorityNumber();
        ~PriorityQueue();

        
};
PriorityQueue::PriorityQueue()
{
    start=nullptr;
}
void PriorityQueue::insert(int p,int data)
{
    Node *n=new Node;
    n->item=data;
    n->pno=p;
    Node *t1,*t2;

    t1=start;
    t2=nullptr;
    
    while(t1!=nullptr)
    {
        if(t1->pno < p)
            break;
        t2=t1;
        t1=t1->next;
    }
    n->next=t1;
    if(t2==nullptr)
        start=n;
    else
        t2->next=n;    
}
void PriorityQueue::deleteItem()
{
    if(isEmpty())
        throw EMPTY_PRIORITY_QUEUE;
    Node *r;
    r=start;
    start=start->next;
    delete r;
}
bool PriorityQueue::isEmpty()
{
    return start==nullptr;
}
int PriorityQueue::getHighestPriorityItem()
{
    if(isEmpty())
        throw EMPTY_PRIORITY_QUEUE;
    return start->item;
}
int PriorityQueue::getHighestPriorityNumber()
{
    if(isEmpty())
        throw EMPTY_PRIORITY_QUEUE;
    return start->pno;
}
PriorityQueue::~PriorityQueue()
{
    while(!isEmpty())
        deleteItem();
}
