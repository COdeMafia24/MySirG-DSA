#include<iostream>
using namespace std;
int sumOdd(int n){
    if(n==0 || n==-1)
        return 0;
    return n+sumOdd(n-2);   
    
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    cout<<"sum odd="<<sumOdd(2*n-1);
    return 0;

}