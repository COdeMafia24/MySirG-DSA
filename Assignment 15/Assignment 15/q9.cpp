#include<iostream>
using namespace std;
void printCube(int n){
    if(n>0){
        printCube(n-1);
        cout<<n*n*n;
    }
    return ;
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    printCube(n);
    return 0;
}