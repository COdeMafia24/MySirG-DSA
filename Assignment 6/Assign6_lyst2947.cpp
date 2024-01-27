#include<iostream>
using namespace std;
class Node
{
    public:
        int item;
        Node *next;
};
class CLL
{
    private:
        Node *last;
    public:
        CLL();
        void insertAtStart(int);
        void insertAtLast(int);
        Node *search(int);
        void insertAfter(Node *,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(int);
        ~CLL();
};
CLL::CLL()
{
    last=nullptr;
}
void CLL::insertAtStart(int data)
{
    Node *n=new Node();
    n->item=data;
    if(last==nullptr)
    {
        n->next=n;
        last=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
    }
}
void  CLL::insertAtLast(int data)
{
    Node *n=new Node();
    n->item=data;
    if(last==nullptr)
    {
        n->next=n;
        last=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
        last=n;
    }
}
Node *CLL::search(int data)
{
    Node *t;
    if(last==nullptr)
        return nullptr;
    t=last->next;
    do{
        if(t->item==data)
            return t;
        t=t->next;
    } while(t!=last->next);
    return nullptr;
}
void CLL::insertAfter(Node *temp,int data)
{
    if(temp)
    {
        Node *n=new Node();
        n->item=data;
        n->next=temp->next;
        temp->next=n;
        if(temp==last)
            last=n;
    }
}
void CLL::deleteFirst()
{
    if(last)
    {
        if(last->next==last)
        {
            delete last;
            last=nullptr;
        }
        else
        {
            Node *t;
            t=last->next;
            last->next=last->next->next;
            delete t;
        }
    }
}
void CLL::deleteLast()
{
    Node *t;
    if(last)
    {
        if(last->next==last)
        {
            delete last;
            last=nullptr;
        }
        else
        {
            t=last->next;
            while(t->next!=last)
                t=t->next;
            t->next=last->next;
            delete last;
            last=t;
        }
    }
}
void CLL::deleteNode(int data)
{
    Node *t,*r;
    if(last)
    {
        if(last->next==last)
        {
            if(last->item==data)
            {
                delete last;
                last=nullptr;
            }
        }
        else
        {
            t=last;
            do{
                if(t->next->item==data)
                {
                    r=t->next;
                    t->next=r->next;
                    if(r==last)
                        last=t;
                    delete r;
                    break;
                }
                t=t->next;
            }while(t!=last);
        }
    }
}
CLL::~CLL()
{
    while(last)
        deleteFirst();
}