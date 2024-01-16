#include<iostream>
#define error 1
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
class SLL{
private:
    Node *start;
   
public:
    SLL();
    void insertAtBeg(int);
    void insertAtEnd(int);
    Node* search(int);
    void insertAtIndex(int,int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    ~SLL();
};
//function
SLL::~SLL(){
    Node *temp;
    temp=start;
    if(start==NULL)
        cout<<"\nZero node in the list,cannot delete";
    else{
        while(temp->next!=NULL){
            temp=temp->next;
            deleteLast();
            temp=start;
        }
    }

}
void SLL::deleteNode(int index){
    Node *prev,*temp;
        temp=start;
        int count=1,n=index;
        while(temp->next!=NULL){
            temp=temp->next;
            count++;
        }
     if(start==NULL)
        cout<<"\nZero node in the list,cannot delete";
    else if(index>=0 && index<count){
        while(n-1){
            n--;
            prev=temp->next;
            temp=temp->next->next;
        }
        prev=temp->next;
        delete temp;
    }
    else if(index==count)
        deleteLast();
    else 
        cout<<"\nCannot delete";
}
void SLL::deleteLast(){
    Node *temp,*prev;
    temp=start;
    prev=start;
     if(start==NULL)
        cout<<"\nZero node in the list,cannot delete";
    else{
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        delete temp;
        

    }
}
void SLL::deleteFirst(){
   
    if(start==NULL)
        cout<<"\nZero node in the list,cannot delete";
    else{
        Node *temp;
        temp=start;
       start=start->next;
       delete temp;
    }
}
void SLL::insertAtIndex(int index,int data){
    Node *n=new Node();
    Node *temp;
    temp=start;
    n->data=data;
    int count=1,n=index;
    while(temp->next!=NULL){
        count++;
    }    
    if(start==NULL){
        start=n;
        start->next=NULL;   
        delete temp;
    }
    else if(index<=count){
        while(n-1){
            temp=temp->next;
            n--;
            
        }
        n->next=temp->next;
        temp->next=n;
    }
    else 
        cout<<"\nCannot insert";
}
Node* SLL::search(int data){
    Node *temp;
    temp=start;
    int node=1;
    if(start==NULL)
        throw error;
    else if(temp->next==NULL){
        if(temp->data==data)
            return temp;
        else 
            return NULL;
    }
    else{
        while(temp->next!=NULL){
            if(temp->data==data){
                return temp;                
            }
            temp=temp->next;
            return temp;
        }       
        if(temp->data=+data)
            return temp;
        else 
            return NULL;
    }
}
void SLL::insertAtBeg(int data){
    Node *n=new Node();
    n->data=data;
    n->next=start;
    start=n;
    
}
void SLL::insertAtEnd(int data){
    Node *n=new Node();
    Node *temp;
    temp=start;
     n->data=data;
     n->next=NULL;
     
   if(start==NULL){       
        start=n;
   }
   else{       
        while(temp->next!=NULL){
            temp=temp->next;
        }
            temp->next=n;   
            
    }
}

SLL::SLL(){
    start=NULL;
}
