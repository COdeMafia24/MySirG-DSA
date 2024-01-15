#include<iostream>
#include<stdio.h>
using namespace std;
#define INVALID_CAPACITY 1
#define EMPTY_ARRAY 2
#define INVALID_INDEX 3
class DynArray
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    protected:
        void doubleArray();
        void halfArray();
    public:
        DynArray(int);
        DynArray(DynArray &);
        void createArray(int);
        int getCapacity();
        bool isEmpty();
        bool isFull();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void del(int);
        int get(int);
        int count();
        ~DynArray();
        int find(int);
        DynArray& operator=(DynArray &);
};
void DynArray::doubleArray()
{
    int *temp;
    temp=new int[capacity*2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    capacity*=2;
    delete []ptr;
    ptr=temp;
}
void DynArray::halfArray()
{
    int *temp;
    temp=new int[capacity/2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    capacity/=2;
    delete []ptr;
    ptr=temp;
}
DynArray::DynArray(int cap)
{
    try{
        if(cap<1)
            throw INVALID_CAPACITY;
        capacity=cap;
        lastIndex=-1;
        ptr=new int[capacity];
    }
    catch(int e)
    {
        cout<<"\nInvalid capacity";
        ptr=NULL;
    }
}
DynArray:: DynArray(DynArray &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    if(arr.ptr==NULL)
        ptr=NULL;
    ptr=new int[capacity];
    for(int i=0;i<=arr.lastIndex;i++)
        ptr[i]=arr.ptr[i];

}
DynArray& DynArray::operator=(DynArray &arr)
{
    if(ptr!=NULL)
        delete []ptr;
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    if(arr.ptr==NULL)
        ptr=NULL;
    ptr=new int[capacity];
    for(int i=0;i<=arr.lastIndex;i++)
        ptr[i]=arr.ptr[i];
}
void DynArray::createArray(int cap)
{
    if(ptr==NULL)
    {
        if(cap<1)
            throw INVALID_CAPACITY;
        capacity=cap;
        lastIndex=-1;
        ptr= new int[capacity];
    }
    else
    {
        if(cap<1)
            throw INVALID_CAPACITY;
        delete []ptr;
        capacity=cap;
        lastIndex=-1;
        ptr= new int[capacity];
    }
}
int DynArray::getCapacity()
{
    return capacity;
}
bool DynArray::isEmpty()
{
    if(ptr==NULL)
        throw INVALID_CAPACITY;
    return lastIndex==-1;
}
bool DynArray::isFull()
{
    if(ptr==NULL)
        throw INVALID_CAPACITY;
    if( capacity==lastIndex+1)
        return true;
    else
        return false;
}
void DynArray::append(int data)
{
    if(ptr==NULL)
        throw INVALID_CAPACITY;
    if(isFull())
        doubleArray();
    
    lastIndex++;
    ptr[lastIndex]=data;
    
}
void DynArray::insert(int index,int data)
{
    int i;
    if(ptr==NULL)
        throw INVALID_CAPACITY;
    if(index<0 || index>lastIndex+1)
        cout<<"\nInvalid Index";
    else if(isFull())
        doubleArray();
   
    for(i=lastIndex;i>=index ;i--)
        ptr[i+1]=ptr[i];
    ptr[index]=data;
    lastIndex++;
    
}
void DynArray::edit(int index,int newData)
{
    if(ptr==NULL)
        throw INVALID_CAPACITY;
    if(index<0 || index>lastIndex)
        cout<<"\nInvalid Index or Empty Array";
    else
        ptr[index]=newData;
    
}
void DynArray::del(int index)
{
    int i;
    if(ptr==NULL)
        throw INVALID_CAPACITY;
    if(index<0 || index>lastIndex)
        cout<<"\nInvalid Index or Empty Array";
    else
    {
        for(i=index;i<lastIndex ;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
        if(capacity>1 && lastIndex<capacity/2)
            halfArray();
    }
}
int DynArray::get(int index)
{
    if(ptr==NULL)
        throw INVALID_CAPACITY;
    if(lastIndex==-1)
        throw EMPTY_ARRAY;
    if(index<0 || index>lastIndex)
        throw INVALID_INDEX;
    return ptr[index];
}
int DynArray::count()
{
    if(ptr==NULL)
        throw INVALID_CAPACITY;
    return lastIndex+1;
}
DynArray::~DynArray()
{
    if(ptr!=NULL)
        delete []ptr;
}
int DynArray::find(int data)
{
    if(ptr==NULL)
        return -1;
    
    for(int i=0;i<=lastIndex;i++)
        if(ptr[i]==data)
            return i;
    return -1;
}
int main()
{
    DynArray obj(4);
    obj.append(10);
    obj.insert(0,20);
    obj.insert(0,30);

    DynArray o1(4);
    o1=obj;


    for(int i=0;i<obj.count();i++)
        cout<<obj.get(i)<<" ";
    obj.del(1);

    cout<<endl;
    for(int i=0;i<obj.count();i++)
        cout<<obj.get(i)<<" ";
    cout<<endl;
    return 0;
}