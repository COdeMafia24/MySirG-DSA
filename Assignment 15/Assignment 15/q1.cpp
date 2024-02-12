#include<iostream>
using namespace std;
void printNatural(int n){
    if(n!=0){
    printNatural(n-1);
    cout<<n;
}}
int main(){
int n;
cout<<"Enter the value of n:";
cin>>n;
printNatural(n);
return 0;
}