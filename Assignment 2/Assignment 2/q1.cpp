#include<iostream>
using namespace std;
class Array{
private:
    int capacity;
    int lastIndex;
    int *ptr=NULL;
public:
    Array(int c){
        if (c>0){

        capacity=c;
        ptr=new int[capacity];
        lastIndex=-1;
        }
    else 
        cout<<"\nEnter a valid size";
    }
    void display(){
        for(int i=0;i<=lastIndex;i++)
            cout<<"\t"<<ptr[i];
    }
    bool isEmpty();
    void append(int);
    void insert(int,int);
    void edit(int,int);
    void deleteElement(int);
    int getElement(int);
    int countElement();
    bool isFull();
    int findElement(int);
    ~Array(){
        delete []ptr;
    }
    //q2 deepcopy
  
   
    Array(Array &a){
        capacity=a.capacity;
        lastIndex=a.lastIndex;
        for(int i=0;i<=lastIndex;i++){
            ptr[i]=a.ptr[i];
        }
    }
 
    //q3 copy assignment operator
    Array operator=(Array &a){
        capacity=a.capacity;
        lastIndex=a.lastIndex;
        for(int i=0;i<=lastIndex;i++){
            ptr[i]=a.ptr[i];
        }
    }

};
//Function Definition
int Array::findElement(int data){
    if(ptr==NULL)
        cout<<"\nArray is not initialized";
    else{
        for(int i=0;i<=lastIndex;i++){
            if(ptr[i]==data)
                return i;
        }
        return -1;
    }
}
bool Array::isFull(){
    if(ptr==NULL)
        cout<<"\nArray is not initialized";
    else if(lastIndex<capacity)
        return 0;
    else
        return 1;
}
int Array::countElement(){
    if(ptr==NULL)
        cout<<"\nArray is not initialized";
    else 
        return lastIndex+1;
    }
int Array::getElement(int index){
    if(ptr==NULL)
        cout<<"\nArray is not initialized";
    else if(index<0 || index>lastIndex)
        cout<<"\nOverflow or Underflow";
    else 
        return ptr[index];
    }
void Array::deleteElement(int index){
    if(ptr==NULL){
        cout<<"\nArray is not initialized";
    }
    else if(index==-1 || index>lastIndex)
        cout<<"\nCannot delete";
    else{
        for(int i=index;i<lastIndex;i++){
            ptr[i]=ptr[i+1];
        }
        --lastIndex;
        printf("\nSuccessfully Deleted");
    }

}
void Array::edit(int index,int data){
    if(ptr==NULL){
            cout<<"\nArray is not initialized";
    }
    else if(index<0 || index==capacity){
        cout<<"\ncannot Edit";
    }
    else{
        ptr[index]=data;
    }
}
void Array::insert(int index,int data){
    int i;
    if(ptr==NULL){
        cout<<"\nArray is not initialized";
    }
    else if(lastIndex==(capacity-1)){
        cout<<"\nCannot insert Overflow";
    }
    else{
        for(i=lastIndex ; i>=index ; i--){
            ptr[i+1]=ptr[i];
        }
        ptr[index]=data;
    }
}
void Array::append(int data){
    if(ptr==NULL){
            cout<<"\nNo array";
    }
    else if(lastIndex<capacity-1){
        ptr[++lastIndex]=data;
    }
    else {

        int *q;
        q=new int[++capacity];
        ptr=q;
        delete []q;
        ptr[++lastIndex]==data;
    }
}
bool Array::isEmpty(){
    if(ptr==NULL){
        cout<<"\nArray is not initialised!";
    }
    else if(lastIndex<capacity){
        return  1;
    }
    else 
        return 0;
}
int main(){
    Array a(4),b(4);
//  b=a; no deep copy
    a.append(5);
    a.display();
    a.deleteElement(2);
     b=a;
    cout<<endl;
    b.append(4);
    cout<<endl;
    b.deleteElement(0);
    b.display();
    cout<<endl;
    a.display();
    
    return 0;
}
