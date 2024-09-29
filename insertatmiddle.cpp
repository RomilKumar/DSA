#include<iostream>
#include<stack>
using namespace std;
 void insertAtMiddle(stack<int>&s,int &count,int  &size,int &value)
 {
//Base Case

if(count==size){
s.push(value);
return;
}
//recursion
size--;
 int topelement=s.top();
 s.pop();
 insertAtMiddle(s,count,size,value);

 //backtrack
 s.push(topelement);

}
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
int size=s.size();
    int count=s.size()/2;
    int value=13;
    //cout<<size;
insertAtMiddle(s,count,size,value);
//print wala kaaam
 while(!s.empty()){
     cout<<s.top()<<" ";
     s.pop();
 }
 return 0;
// }

}