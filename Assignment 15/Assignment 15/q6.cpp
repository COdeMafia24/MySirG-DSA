#include<iostream>
using namespace std;
void printEvenRev(int n){
    if(n>-1){
        cout<<n;
        printEvenRev(n-2);
    }
    return ;
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    printEvenRev(2*n-2);
    return 0;
}