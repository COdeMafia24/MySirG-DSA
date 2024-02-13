#include<iostream>
using namespace std;
int sumNaturalSquare(int n){
    if(n==0)
        return 0;
    return n*n +sumNaturalSquare(n-1);
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    cout<<"sum is "<<sumNaturalSquare(n);
    return 0;
}