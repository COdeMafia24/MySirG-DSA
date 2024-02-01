#include <iostream>
using namespace std;
class Node
{
public:
    int item;
    Node *next;
};
class Stack
{
private:
    Node *top;

public:
    void show();
    Stack();
    void push(int);
    int peek();
    void pop();
    ~Stack();
    Node *reverseStack();
    bool palindrome();
};
// function definition
void Stack::show()
{
    Node *t;
    t = top;
    while (t)
    {
        cout << endl
             << t->item;
        t = t->next;
    }
}

bool Stack::palindrome()
{
    Node *t1, *head, *head2,*t2;

        head=top;
        int count=0;
        while(head){
            count++;
            head=head->next;
        }      
        int a[count],b[count];
        t1 = reverseStack();
        head=t1;           
        for(int i=0;i<count;i++){
                a[i]=head->item;        
                head=head->next;
            }

        t2 = reverseStack();   
        head2=t2;        
        for(int i=0;i<count;i++){
                 b[i]=head2->item;                  
                 head2=head2->next;
            }
            
        for(int i=0;i<count;i++){
                if(a[i]!=b[i])
                    return false;
            }      
                
        return true;
        
        
    
}

Node *Stack::reverseStack()
{
    if (top == NULL)
    {
        cout << endl
             << "cannot reverse, no element";
    }
    else
    {
        Node *n, *R = NULL, *t, *p;
        while (top)
        {
            p = NULL, t = top;
            while (t->next != NULL)
            {
                p = t;
                t = t->next;
            }
            if (top->next != NULL)
                p->next = NULL;
            else
            {
                // delete top;
                top = NULL;
            }
            if (R == NULL)
            {
                R = t;
            }
            else
            {
                n = R;
                while (n->next != NULL)
                {
                    n = n->next;
                }
                n->next = t;
            }
        }
        top = R;
        cout << "\nReversed successfully";
    }
    return top;
}

Stack::~Stack()
{
    while (top)
    {
        pop();
    }
    cout << "\n!end";
}

void Stack::pop()
{
    if (top == NULL)
        cout << endl
             << "No element in the stack";
    else
    {
        Node *t;
        t = top;
        top = top->next;
        delete t;
    }
}

int Stack::peek()
{
    if (top == NULL)
        return -1;
    else
        return top->item;
}

void Stack::push(int data)
{

    Node *newNode = new Node;
    newNode->item = data;
    newNode->next = top;
    top = newNode;
    cout << "\nPushed";
}

Stack::Stack()
{
    top = NULL;
}

int main()
{
    Stack S;
    S.push(5);
    S.push(13);
    S.push(3);
    S.push(5);
    S.show();
    S.reverseStack();
    S.show();
    cout << endl
         << S.palindrome();
    return 0;
}