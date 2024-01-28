#include<iostream>
using namespace std;
class Node
{
    public:
        Node *prev;
        int item;
        Node *next;
};
class CDLL
{
    private:
        Node *start;
    public:
        CDLL();
        void insertAtStart(int);
        void insertAtLast(int);
        Node *search(int);
        void insertAfter(Node*,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(int);
        ~CDLL();
};
CDLL::CDLL()
{
    start=nullptr;
}
void CDLL::insertAtStart(int data)
{
    Node *n=new Node;
    n->item=data;
    if(start==nullptr)
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
        start=n;
    }
}
void CDLL::insertAtLast(int data)
{
    Node *n=new Node;
    n->item=data;
    if(start==nullptr)
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
    }
}
Node *CDLL::search(int data)
{
    if(start==nullptr)
        return nullptr;
    Node *t;
    t=start;
    do
    {
        if(t->item==data)
            return t;
        t=t->next;
    }while(t!=start);
    return nullptr;
}
void CDLL::insertAfter(Node* temp,int data)
{
    if(temp)
    {
        Node *n=new Node;
        n->item=data;
        n->prev=temp;
        n->next=temp->next;
        temp->next->prev=n;
        temp->next=n;
    }
}
void CDLL::deleteFirst()
{
    if(start)
    {
        if(start->next==start)
        {
            delete start;
            start=nullptr;
        }
        else
        {
            Node *r;
            r=start;
            start->prev->next=start->next;
            start->next->prev=start->prev;
            start=start->next;
            delete r;
        }
    }
}
void CDLL::deleteLast()
{
    if(start)
    {
        if(start->next==start)
        {
            delete start;
            start=nullptr;
        }
        else
        {
            Node *r;
            r=start->prev;
            r->prev->next=start;
            start->prev=r->prev;
            delete r;
        }
    }
}
void CDLL::deleteNode(int data )
{
    if(start)
    {
        if(start->next==start)
        {
            if(start->item==data)
            {
                delete start;
                start=nullptr;
            }
        }
        else
        {
            Node *t;
            t=start;
            do{
                if(t->item==data)
                {
                    t->prev->next=t->next;
                    t->next->prev=t->prev;
                    if(t==start)
                        start=t->next;
                    delete t;
                }
                t=t->next;
            }while(t!=start);
        }
    }
}
CDLL::~CDLL()
{
    while(start)
        deleteFirst();
}