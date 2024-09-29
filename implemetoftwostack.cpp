#include<iostream>

using namespace std;
class stack{
public:
int top1;
int top2;
int size;
int *arr;
  stack(int capacity){
    arr=new int[capacity];
    top1=-1;
     size=capacity;
    top2=size;
  }
//pushing from top and bottom according to the function called
void push1(int value){
    if (top2-top1==1){
        cout<<"stack overflow";
    }
    else{
        top1=top1+1;
      arr[top1]=value;
    }
}
void push2(int data){
    if (top2-top1==1){
        cout<<"stack overflow";
    }
    else{
        top2--;
        arr[top2]=data;

    }
}
void pop1(){
    //stack is empty 
    if (top1==-1){
cout<<"stack underflow";
    }
    
    else{
arr[top1]==0;
top1--;}
}
void pop2(){
  if(top2 == size) {
              //stack 2 is empty, no element to pop
              cout << "Stack Underflow" << endl;
            }
            else {
              arr[top2] = 0;
              top2++;
            }
}
void print (){
  cout << "Top1: " << top1 << endl;
          cout << "Top2: " << top2 << endl;
          for(int i=0; i<size; i++) {
            cout << arr[i] << " ";
          }
}

};




int main(){
   stack s(5);
   s.push1(10);
   s.push2(20);
   //s.print();
   s.pop1();
   s.pop2();
   s.print();
  
}