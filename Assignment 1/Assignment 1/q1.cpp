//initialized array by 1111(random large no)
#include<iostream>
using namespace std;
class Array{
private:
    int capacity;
    int lastIndex;
    int *p;
public:
    Array(int c){
        capacity=c;
        p=new int[capacity];
        for(int i=0;i<capacity;i++){            
            p[i]=1111;
        }
        lastIndex=-1;
    }
    void display(){
        cout<<endl;
        for(int i=0;i<capacity;i++)
            cout<<"\t"<<p[i];
    }
    bool CheckEmpty(){
        for(int i=0;i<capacity;i++){
            if(p[i]!=1111)
                return false;
        }
        return true;
    }
    void append(int x){
        if(lastIndex<capacity-1){
            p[++lastIndex]=x;
        }
        else{
            int *q,i;
            q=new int[++capacity];
            for(i=0;i<capacity-1;i++){
                q[i]=p[i];
            }
            delete []p;
            p=new int[capacity];
           for(i=0;i<capacity-1;i++){
                p[i]=q[i];
            }
            p[i]=x;
            delete []q;
            ++lastIndex;
        } 
    }
    void insertIndex(int x,int y){
        if(x<capacity && x>-1){
            p[x]=y;
            lastIndex=x;
        }
        else{
            cout<<"\nCannot insert,Illegal memory access";
        }
    }
    void editElement(int x,int y){
        if(x<capacity && x>-1){
            p[x]=y;
        }
        else{
            cout<<"\nCannot Edit ,Illegal memory access!";
        }
    }
    void deleteElement(int x){
        if(x<capacity && x>-1){
            p[x]=1111;
        }
        else{
            cout<<"\nCannot Delete,Illegal memory access!";
        }
    }
    bool checkArrayFull(){
        for(int i=0;i<capacity;i++)
            if(p[i]==1111)
                return false;
        return true;
    }
    int getElement(int x){
        if(x<capacity && x>-1)
            return p[x];
        else 
            cout<<"\nIllegal memory access";
    }
    int count(){
        int count=0;
        for(int i=0;i<capacity;i++)
            if(p[i]!=1111)
                count++;
        return count;
    }
    int findElement(int x){
        for(int i=0;i<capacity;i++)
            if(p[i]==x)
                return i;
        return -1; 
    }
    ~Array(){
        delete []p;
    }
};
int main(){
    Array a(3);
    a.display();
    cout<<endl<<a.CheckEmpty();
    //append in <capacity Index
    a.append(5);
    a.display();
    //insert at specific Index
    a.insertIndex(2,25);
    a.display();
    //edit at specific index
    a.editElement(2,20);
    a.display();
    //append at capacity index
    a.append(50);
    a.display();
    //delete 
    a.deleteElement(3);
    a.display();
    //check array full or not
    cout<<endl<<a.checkArrayFull();
    //get element at specific index
    cout<<endl<<a.getElement(3);
    //count
    cout<<endl<<a.count();
    //find element is present in array present i/-1
    cout<<endl<<a.findElement(2);
    return 0;
}
