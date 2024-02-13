#include<iostream>
using namespace std;
void binary(int n){
    if(n!=0){
         binary(n/2);
         cout<<n%2;
    }
    
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    binary(n);
    return 0;
}