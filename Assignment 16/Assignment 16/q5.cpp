#include<iostream>
using namespace std;
int fact(int n){
    if(n==1)
        return 1;
    return n*fact(n-1);
}
int main(){
int n;
cout<<"Enter the value of n:";
cin>>n;
cout<<"factorial of "<<n<<"! is "<<fact(n);
return 0;
}