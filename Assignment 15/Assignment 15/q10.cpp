#include<iostream>
using namespace std;
void printCubeRev(int n){
    if(n>0){
        cout<<n*n*n;
        printCubeRev(n-1);
    }
    return ;
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    printCubeRev(n);
    return 0;
}