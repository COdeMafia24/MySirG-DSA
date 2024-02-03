#include<iostream>
using namespace std;
#define OVERFLOW 1
#define EMPTY 2
class Queue
{
    private:
        int capacity;
        int front, rear;
        int *ptr;
    public:
        Queue(int);
        void enqueue(int);
        bool isFull();
        bool isEmpty();
        int getFront();
        int getRear();
        void dequeue();
        ~Queue();
        int size();
};
Queue::Queue(int cap)
{
    capacity=cap;
    front=rear=-1;
    ptr=new int[cap];
}
void Queue::enqueue(int data)
{
    if(isFull())
       throw OVERFLOW; 
    if(isEmpty())
        rear=front=0;
    else if(rear==capacity-1)
        rear=0;
    else
        rear++;
    ptr[rear]=data;

}
bool Queue::isFull()
{
    if(front==0 && rear==capacity-1 || rear==front-1)
        return true;
    return false;
}
bool Queue::isEmpty()
{
    return front==-1;
}
int Queue::getFront()
{
    if(isEmpty())
        throw EMPTY;
    return ptr[front];
}
int Queue::getRear()
{
    if(isEmpty())
        throw EMPTY;
    return ptr[rear];
}
void Queue::dequeue()
{
    if(isEmpty())
        throw EMPTY;
    if(front==rear)
        front=rear=-1;
    else if(front==capacity-1)
        front=0;
    else
        front++;
}
Queue::~Queue()
{
    delete []ptr;
}
int Queue::size()
{
    if(front>rear)
        return capacity-(front-rear)+1;
    else
        return rear-front+1;
}