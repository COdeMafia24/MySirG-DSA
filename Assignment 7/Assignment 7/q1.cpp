#include<iostream>
using namespace std;
class Node{
public:
    int item;
    Node *prev;
    Node *next;
};
class CDLL{
private:
    Node *start;
public:
    CDLL();
    void insertAtFirst(int);
    void insertAtLast(int);
    Node* searchNode(int);
    void insertNode(Node*,int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    ~CDLL();
};
//function definition
CDLL::~CDLL(){
    while(start)
        deleteFirst();
}
void CDLL::deleteNode(int data){
    if(start==NULL)
        cout<<"\nzero node in the list";
    else if(start->next==NULL && start->prev==NULL){    
            delete start;
            start=NULL;        
    }
    else{
        Node *temp=start;
        do{
            if(temp->item==data){
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                if(temp==start){
                    start=temp->next;
                }
                delete temp;
            }
            temp=temp->next;

        }while(temp);
    }
}
void CDLL::deleteLast(){
    if(start==NULL)
        cout<<"\nzero node in the list";
    else if(start->next==NULL && start->prev==NULL){

        delete start;
        start=NULL;
    }
    else{
        Node *temp=start;
        while(temp->next!=start){
            temp=temp->next;
        }
        temp->prev->next=start;
        start->prev=temp->prev;
        delete temp;

    }
}
void CDLL::deleteFirst(){
    if(start==NULL)
        cout<<"\nzero nodes in the list";
    else if(start->next==NULL && start->prev==NULL){

        delete start;
        start=NULL;
    }
    else    
        {
            Node *temp=start;
            start=temp->next;
            temp->prev->next=start;
            start->prev=temp->prev;
            delete temp;
        }
}
void CDLL::insertNode(Node* temp,int data){
    Node *newNode=new Node();
    newNode->item=data;
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next->prev=newNode;
    temp->next=newNode;

}
Node* CDLL::searchNode(int data){
    if(start==NULL){
        cout<<"\n Zero element in the list";
        return NULL;
    }
    else{
        Node *temp=start;
        do{
            if(temp->item==data)
                return temp;
            temp=temp->next;
        }while(temp==start);
        return NULL;
    }
}
void CDLL::insertAtLast(int data){
    Node *newNode=new Node();
    newNode->item=data;
    if(start==NULL){
        newNode->next=newNode;
        newNode->prev=newNode;
        newNode=start;
    }
    else{
        newNode->next=start;
        newNode->prev=start->prev;
        start->prev->next=newNode;
        start->prev=newNode;
    }
}
CDLL::CDLL(){start=NULL;}
void CDLL::insertAtFirst(int data){
    Node *newNode=new Node();
    newNode->item=data;
    if(start==NULL){
        newNode->next=newNode;
        newNode->prev=newNode;
        start=newNode;
    }
    else{
        newNode->next=start;
        newNode->prev=start->prev;
        start->prev->next=newNode;
        start->prev=newNode;
        newNode=start;
    }
}
