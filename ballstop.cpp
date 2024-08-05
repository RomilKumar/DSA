#include<iostream>
using namespace std;
int main(){
    int v;
    cout<<"enter the value of velocity:";
    cin>>v;
    int dip=0;
    while(v>0){
        v=v/2;
dip=dip+1;

    }
    cout<<"time taken:"<<dip;
    return 0;
}