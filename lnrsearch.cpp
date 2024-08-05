#include<iostream>
using namespace std;
bool search(int arr[],int size,int index,int target){
//base condition
for(int i=0;i<size;i++){
if(index>=size){
return false;
}
if(arr[index]==target){
  return  true;
  }
}

search(arr,size,index+1,target);
}
int main(){
int arr[]={10,20,30,40,50};
int size=5;
int index=0;
int target=10;
 bool ans=search(arr,size,index,target);
 cout<<ans;

return 0;
}