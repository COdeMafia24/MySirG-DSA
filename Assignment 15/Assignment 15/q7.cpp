#include<iostream>
using namespace std;
void printSquare(int n){
    if(n>0){
        printSquare(n-1);
        cout<<n*n;
    }
    return ;
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    printSquare(n);
    return 0;
}