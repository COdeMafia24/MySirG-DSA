#include<iostream>
using namespace std;
class Node{
public:
    int item;
    Node *next;
};
class CLL{
private:
    Node *last=NULL;
public:
    CLL();
    void insertAtFirst(int);
    void insertAtEnd(int);
    Node* search(int);
    void insertAfter(Node*,int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    ~CLL();
};
//function defination
CLL::~CLL(){
    while(last){
        deleteFirst();
    }
}
void CLL::deleteNode(int data){
    Node *temp1,*temp2;
    temp1=last->next;
    temp2=last;
    if(last){
        if(last==last->next){            
            if(last->item==data)
                delete last;
                last==NULL;
        }
        else{
            while(temp1!=last){
                if(temp1->item==data){
                }
                temp2=temp1;
                temp1=temp1->next;
            }           
                temp2->next=temp1->next;
                if(temp1==last)
                    last=temp2;
                delete temp1;                    
        }
    }
}
void CLL::deleteLast(){
    Node *temp;
    if(last){
        if(last==last->next)
            delete last;
            last=NULL;    
    }
        else{
            temp=last->next;
            while(temp->next!=last){
                temp=temp->next;
            }
                temp->next=last->next;
                delete last;
                last=temp;
        }
}
void CLL::deleteFirst(){
    Node *temp;
    if(last){
        if(last==last->next){
            delete last;
            last=NULL;
        }
        else{            
        temp=last->next;
        last->next=temp->next;
        delete temp;
        }
    }
}
void CLL::insertAfter(Node*after,int data){
    Node* temp=new Node();
    temp->item=data;
    if(last){
        if(last==after){
            temp->next=after->next;
            after->next=temp;
            temp=last;
        }
        else{
            temp->next=after->next;
            after->next=temp;
        }        
    }
    else{
        temp->next=temp;
        last=temp;
    }
    
}
Node* CLL::search(int data){
    Node *temp;
    if(last){
    temp=last->next;
    while(temp!=last){
        if(temp->item==data){
            return temp;
        }
        temp=temp->next;
    }        
        if(temp->item==data)
            return temp;
  }
  return NULL;
} 
void CLL::insertAtFirst(int data){
    Node *temp=new Node();
    temp->item=data;   
    if(last==NULL){
        last=temp;
        temp->next=temp;
    }
    else{
        temp->next=last->next;
        last->next=temp;    
    }
}
void CLL::insertAtEnd(int data){
    Node *temp=new Node();
    temp->item=data;
    if(last==NULL){
        last=temp;
        temp->next=temp;
    }
    else{
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }
        

}
CLL::CLL(){
    last=NULL;    
}
