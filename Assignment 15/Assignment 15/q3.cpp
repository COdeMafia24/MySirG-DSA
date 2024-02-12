#include<iostream>
using namespace std;
void printOdd(int n){
    if(n>0){
        printOdd(n-2);
        cout<<n;
    }
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    printOdd(2*n-1);
    return 0;
}