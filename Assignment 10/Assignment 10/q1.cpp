#include<iostream>
using namespace std;
class Queue{
private:
    int capacity;
    int front;
    int rear;
    int *ptr;
    int count=0;
public:
    Queue(int);
    void insert(int);
    int underflow();
    int overflow();
    int rearElement();
    int frontElement();
    void deleteEl();
    ~Queue();
    int countElements();
};
//function definition
int Queue::countElements(){
    return count;
}
Queue::~Queue(){
    while(!underflow())
        deleteEl();
}
void Queue::deleteEl(){
    if(underflow())
        cout<<endl<<"No element int the Q!";
    else{
        count--;
        cout<<endl<<"deleted element is "<<ptr[front];
        if(front==rear)
            front=rear=-1;
        else 
            front++;
    }
}
int Queue::rearElement(){
    if(underflow())
        cout<<endl<<"No elememt in the Q!";
    return ptr[rear];
}
int Queue::frontElement(){
    if(underflow()){
        cout<<endl<<"No element in the Q";
        return -1;
    }
    return ptr[front];
}
int Queue::underflow(){
    if(front==-1)
        return 1;
    return 0;
}
int Queue::overflow(){
    if(rear==capacity-1)
        return 1;
    return 0;
}
void Queue::insert(int data){
    if(overflow()){
        cout<<endl<<"Overflow";
    }
    else{
        count++;
        rear++;
        ptr[rear]=data;
    }
}
Queue::Queue(int c){
    capacity=c;
    front=-1;
    rear=-1;
    ptr=new int[capacity];
}