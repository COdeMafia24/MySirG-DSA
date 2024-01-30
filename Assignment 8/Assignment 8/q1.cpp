#include<iostream>
using namespace std;
class Stack{
private:
    int capacity;
    int top;
    int *ptr;
public:
    void showStack();
    Stack(int);
    void push(int);
    int peek();
    void pop();
    ~Stack();
    int overflow();
    int underflow();
    void reverseStack();
    int minElement();
};
//function definition
void Stack::showStack(){
    cout<<endl<<"Stack:"<<endl;
    for(int i=top;i>=0;i--)
        cout<<endl<<ptr[i];
}
int Stack::minElement(){
    if(top==-1){        
        cout<<"\nStack is empty";
        return -1;
    }
    else{
        int min=ptr[0];
        for(int i=1;i<=top;i++)
            if(min>ptr[i])
                min=ptr[i];
        return min;        
    }
}
void Stack::reverseStack(){
    int t;
    for(int i=0;i<top/2;i++){
        t=ptr[i];
        ptr[i]=ptr[top-i];
        ptr[top-i]=t;
    }
    cout<<"\nSuccessfully reversed";
}
int Stack::underflow(){
    if(top==-1)
        return 1;
    else    
        return 0;
}
int Stack::overflow(){
    if(top==capacity-1){
        cout<<"\noverflow!";
        return 1;
    }
    else
        return 0;
}
Stack::~Stack(){
    delete []ptr;
}
void Stack::pop(){
    if(underflow())// if(top==-1)
        cout<<"\nNo elements in the stack";
    else{
        cout<<"\nPoped element is "<<ptr[top];
        top--;
    }
}
int Stack::peek(){
    if(top==-1)
        return -1;
    else
        return ptr[top];
}
void Stack::push(int data){
    if(overflow())//if(top==capacity-1)
        cout<<"\nCannot push! stack is full";
    else{
        ptr[++top]=data;
    }
}
Stack::Stack(int c){
    top=-1;
    capacity=c;
    ptr=new int[c];

}
int main(){
    Stack s(5);
    s.pop();
    cout<<endl<<s.overflow();
    cout<<endl<<s.underflow();
    s.push(5);
    s.push(6);
    s.push(45);
    s.push(3);
    s.push(15);
    s.push(15);
    s.showStack();
    s.reverseStack();
    s.showStack();
    s.pop();
    s.showStack();
    cout<<endl<<"min element in the stack="<<s.minElement();
    cout<<endl<<s.peek();
    return 0;
}