#include<iostream>
using namespace std;
int sumNatural(int n){
    if(n==0 || n==1)
        return 0;
    return n+sumNatural(n-2);
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    cout<<"sum = "<<sumNatural(2*n);
    return 0;
}