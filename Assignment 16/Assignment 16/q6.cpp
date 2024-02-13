#include<iostream>
using namespace std;
int sumDigit(int n){
    if(n!=0){
        return n%10+sumDigit(n/10);
    }
    return 0;
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    cout<<"sum of digits is "<<sumDigit(n);
    return 0;
}
