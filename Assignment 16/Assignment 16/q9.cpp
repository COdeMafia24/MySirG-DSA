#include<iostream>
using namespace std;
int hcf(int a,int b){
    if(a>b){
        if(a%b==0)
            return b;
        else{
            hcf(a%b,b);
        }
    }
    else{
        if(b%a==0)
            return a;
        else{
            hcf(a,b%a);
        }
    }
}
int main(){
    int a,b;
    cout<<"Enter the value of a and b:";
    cin>>a>>b;
    cout<<"hcf :"<<hcf(a,b);
