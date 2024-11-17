#include<iostream>
using namespace std;
TOH(int n, char F, char A, char T){
   //base condition
   if(n==1) {
    cout<<"Move first disk "<<F<<"to disk"<<T;
   }
   else{
    TOH(n-1,char F,char T, char A)
//F se T me bhejo using A
  cout << "Move disk " << n << " from rod " << F
         << " to rod " << T << endl;

TOH(n-2, char A,char F,char T);
   }
}



int main(){
int n;
cout<<"enter no of discs";
cin>>n;
TOH(n,'F','A','T');


}