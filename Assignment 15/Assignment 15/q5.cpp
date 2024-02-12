#include<iostream>
using namespace std;
void printEven(int n){
    if(n>-1){
        printEven(n-2);
        cout<<n;
    }
    return ;
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    printEven(2*n-2);
    return 0;
}