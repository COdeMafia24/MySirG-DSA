#include<iostream>
using namespace std;
class Node{
public:
    int item;
    Node *prev;
    Node *next;
};
class DLL{
private:
    Node *start;
public:
    DLL();
    void insertAtStart(int);
    void insertAtEnd(int);
    Node* search(int);
    void insertAfter(Node *,int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    ~DLL();
};
    

//function definition
void DLL::deleteNode(int data){
    Node *t1,*t2;
    t1=start;
    t2=NULL;
    if(start){
        while(t1->item==data){
            break;
        t2=t1;
        t1=t1->next;        
        } 
        if(t1){

            if(t2==NULL){
                start=t1->next;
                start->prev=NULL;           
                delete t1;
            }
            else{                
                    t2=t1->next;
                    t1->next->prev=t2;
                    delete t1;                

            }
        }   
    }
}
void DLL::insertAfter(Node *temp,int data){
    Node *n=new Node();
    if(temp){
        n->item=data;
        n->next=temp->next;
        temp->next=n->prev;
    }
}
DLL::~DLL(){
    while(start){
        deleteFirst();
    }
}
void DLL::deleteLast(){
    Node *temp;
    temp=start;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev=NULL;
    delete temp;
}
void DLL::deleteFirst(){
    Node *temp;
    temp=start;
    start=temp->next;
    delete temp;
}
Node* DLL::search(int data){
    Node *temp;
    temp=start;
    while(temp){
        if(temp->item==data)
            return temp;
        temp=temp->next;
    }   
    return NULL;
}
void DLL::insertAtEnd(int data){
    Node *n=new Node();
    Node *temp;
    n->item=data;
    if(start==NULL){
        start=n;
        n->prev=NULL;
        n->next=NULL;
    }
    else{
        temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n->prev;
        n->next=NULL;
    }
}
void DLL::insertAtStart(int data){
        Node *n=new Node();
        n->item=data;
        n->prev=NULL;
        n->next=start;
        start=n;
}
DLL::DLL(){ start=NULL;}