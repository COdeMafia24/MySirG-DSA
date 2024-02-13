#include<iostream>
using namespace std;
int power(int a,int b){
    if(b!=0)
        {
            return a*power(a,b-1);
        }
}
int main(){
    int a,b;
    cout<<"Enter a no :";
    cin>>a;
    cout<<"Enter power:";
    cin>>b;
    cout<<"result:"<<power(a,b-1);
    return 0;
}