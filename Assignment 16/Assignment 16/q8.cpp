#include<iostream>
using namespace std;
int fibo(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return fibo(n-2)+fibo(n-1);
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    cout<<n<<"th term of fibo series is "<<fibo(n);
    return 0;
}