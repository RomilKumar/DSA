#include<iostream>
using namespace std;
#include<stack>
void insetAtTail(stack<int>&s,int value){
//Base condition
if(s.empty()){
    s.push(value);
    return;
}
//ek kaam m karunga ie pop wala and aage ka kaam recursion ko pakda dunga

    int topelement=s.top();
    s.pop();

    insetAtTail(s,value);

//backtracking
s.push(topelement);

}


int main(){
stack<int>s;
s.push(10);
s.push(20);
s.push(30);
s.push(40);
s.push(50);

insetAtTail(s,60);

//printing
while(!s.empty()){
      cout<<s.top()<<" ";
    s.pop();
}
}