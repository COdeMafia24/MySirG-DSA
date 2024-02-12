#include<iostream>
using namespace std;
void f1(int n)
{
    if(n>0)
    {
        f1(n-1);
        cout<<" "<<n;
    }
}
void f2(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        f2(n-1);
    }
}
void f3(int n)
{
    if(n>0)
    {
        f3(n-1);
        cout<<" "<<2*n-1;
    }
}
void f4(int n)
{
    if(n>0)
    {
        cout<<2*n-1<<" ";
        f4(n-1);
    }
}
void f5(int n)
{
    if(n>0)
    {
        f5(n-1);
        cout<<" "<<2*n;
    }
}
void f6(int n)
{
    if(n>0)
    {
        cout<<2*n<<" ";
        f6(n-1);
    }
}
void f7(int n)
{
    if(n>0)
    {
        f7(n-1);
        cout<<" "<<n*n;
    }
}
void f8(int n)
{
    if(n>0)
    {
        cout<<n*n<<" ";
        f8(n-1);
    }
}
void f9(int n)
{
    if(n>0)
    {
        f9(n-1);
        cout<<" "<<n*n*n;
    }
}
void f10(int n)
{
    if(n>0)
    {
        cout<<n*n*n<<" ";
        f10(n-1);
    }
}