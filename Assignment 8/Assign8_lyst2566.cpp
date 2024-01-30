#include<iostream>
using namespace std;
#define STACK_OVERFLOW 1
#define STACK_EMPTY 2
class Stack
{
    private:
        int capacity;
        int top;
        int *ptr;
    public:
        Stack(int);
        bool isFull();
        bool isEmpty();
        void push(int);
        int peek();
        void pop();
        int size();
        ~Stack();
};
Stack::Stack(int cap)
{
    capacity=cap;
    top=-1;
    ptr=new int[cap];
}
bool Stack::isFull()
{
    if(capacity-1==top)
        return true;
    return false;
}
bool Stack::isEmpty()
{
    if(top==-1)
        return true;
    return false;
}
void Stack::push(int data)
{
    if(isFull())
        throw STACK_OVERFLOW;
    top++;
    ptr[top]=data;
}
int Stack::peek()
{
    if(isEmpty())
        throw STACK_EMPTY;
    return ptr[top];
}
void Stack::pop()
{
    if(isEmpty())
        throw STACK_EMPTY;
    top--;
}
Stack::~Stack()
{
    delete []ptr;
}
int Stack::size()
{
    return top+1;
}
void reverseStack(Stack &s1)
{
    Stack s2(s1.size()),s3(s1.size());
    while(!s1.isEmpty())
    {
        s2.push(s1.peek());
        s1.pop();
    }
    while(!s2.isEmpty())
    {
        s3.push(s2.peek());
        s2.pop();
    }
    while(!s3.isEmpty())
    {
        s1.push(s3.peek());
        s3.pop();
    }
}

void minValue()
{
    Stack s1(10),minStack(10);
    int choice,data;
    bool flag=true;
    while(flag){
    cout<<"\n1. Push";
    cout<<"\n2. Pop";
    cout<<"\n3. Peek";
    cout<<"\n4. Current min value";
    cout<<"\n5. Exit";
    cout<<"\nEnter your choice";
    cin>>choice;
    switch(choice)
    {
        case 1:
            cout<<"Enter data: ";
            cin>>data;
            s1.push(data);
            if(minStack.isEmpty())
                minStack.push(data);
            else
                if(minStack.peek() > data)
                    minStack.push(data);
                else
                    minStack.push(minStack.peek());
            break;
        case 2:
            s1.pop();
            minStack.pop();
            break;
        case 3:
            cout<<"Top element on the stack is "<<s1.peek();
            break;
        case 4:
            cout<<"Current min value is "<<minStack.peek();
            break;
        case 5:
            flag=false;
            break;
        default:
            cout<<"Invalid Choice";
    }
    cout<<endl;
    }
}
int main()
{
    minValue();
    cout<<endl;
    return 0;
}


