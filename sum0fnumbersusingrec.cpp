#include<iostream>
using namespace std;
int printsum(int n){
    //base condition
    if(n==1){
        return 1;
    }
   
    //recursive call
  int ans=n+ printsum(n-1);
  return ans;
     
    
}
int main(){
int n;
cout<<"enter a number:";
cin>>n;
 int finalans=printsum(n);
cout<<"final answer:"<<finalans;
return 0;
}