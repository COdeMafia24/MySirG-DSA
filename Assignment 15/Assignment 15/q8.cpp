#include<iostream>
using namespace std;
void printSquareRev(int n){
    if(n>0){
        cout<<n*n;
        printSquareRev(n-1);
    }
    return ;
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    printSquareRev(n);
    return 0;
}