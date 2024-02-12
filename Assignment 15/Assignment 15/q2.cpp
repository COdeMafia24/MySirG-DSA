#include<iostream>
using namespace std;
void printRev(int n){
    if(n!=0){
        cout<<n;
        printRev(n-1);
    }
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    printRev(n);
    return 0;
}