#include<iostream>
using namespace std;
void printOddRev(int n){
    if(n>-1){
        cout<<n;
        printOddRev(n-2);
    }
    return ;
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    printOddRev(2*n-1);
    return 0;
}