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
    int currentCapacity();
 protected:  //taki only insert,delete,append he use kar paye member fun call se   
    void doubleArray();
    void halfArray();
   

};
//Function Definition
int Array::currentCapacity(){
    return capacity;
}
void Array::halfArray(){
    if(ptr==NULL)
        cout<<"\nArray not initialized";
    else {
        
        if(lastIndex<(capacity/2) && (capacity>1)){
            
            int *q;           
            q=new int[capacity/2];
            for(int i=0;i<=lastIndex;i++){
                q[i]=ptr[i];
            }
            capacity/=2;
            delete []ptr;
            ptr=q;            
            delete []q;
            
        }
    }
}
void Array::doubleArray(){
    if(ptr==NULL)
        cout<<"\nCannot double";
    else{
        if(lastIndex==(capacity-1)){
            int *q;
            capacity*=2;
            q=new int[capacity];
            for(int i=0;i<=lastIndex;i++){
                q[i]=ptr[i];
            }
            delete []ptr;
            ptr=q;
            delete []q;
            
        }
    }
}
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
        lastIndex--;        
        halfArray();
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
    else if(index>capacity)
        cout<<"\nIllegal memory acces";
    else if(lastIndex==(capacity-1)){
        doubleArray();
        ptr[++lastIndex]=data;
    }
    else{
        for(i=lastIndex ; i>=index ; i--){
            ptr[i+1]=ptr[i];
        }
        ptr[index]=data;
        lastIndex++;
    }
    halfArray();
}
void Array::append(int data){
    if(ptr==NULL){
            cout<<"\nNo array";
    }
    else if(lastIndex<capacity-2){
        ptr[++lastIndex]=data;
       // halfArray();
    }
    else {       
        doubleArray();
        ptr[++lastIndex]=data;
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
    Array a(2);

    a.append(5);
    //a.append(35);
    //a.append(55);
  //  a.append(45);  
    a.display();
    cout<<endl<<a.currentCapacity();
    a.deleteElement(0);   
    //a.deleteElement(1);   
    cout<<endl; 
    a.display();
    cout<<endl<<a.currentCapacity();

    
    return 0;
}
