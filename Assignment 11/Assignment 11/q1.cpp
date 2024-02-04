#include<iostream>
using namespace std;
class Node{
public:
    int item;
    Node *next;
};
class Queue{
private:
    Node *front;
    Node *rear;
    int count=0;
public:
    Queue();
    void insert(int);
    int viewRear();
    int viewFront();
    void deleteFront();
    ~Queue();
    int countNode();
};
//function defintion
int Queue::countNode(){
    return count;
}
Queue::~Queue(){
    Node *temp=front;
    while(temp){
        deleteFront();
        temp=temp->next;
    }
}
void Queue::deleteFront(){
    if(front==NULL){
        cout<<endl<<"NO element in the Q!";
        return ;
    }
    Node *temp;
    temp=front;
    front=front->next;
    delete temp;
    count--;
}
int Queue::viewFront(){
    if(front==NULL){
        cout<<endl<<"No elements in the Q!";
        return -1;
    }
    else
        return front->item;
}
int Queue::viewRear(){
    if(front==NULL){
        cout<<endl<<"NO elements! in the Q";
        return -1;
    }
    else    
        return rear->item;
}
void Queue::insert(int data){
    Node *temp=new Node();
    temp->item=data;
    if(front==NULL){
        front=temp;
        rear=temp;
    }
    else{
        rear->next=temp;
        temp->next=NULL;
        rear=temp;

    }
    count++;

}
Queue::Queue(){
    front=rear=NULL;
}