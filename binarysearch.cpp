#include <iostream>
#include<vector>
using namespace std;
int search(vector<int>&arr,int target)
{
   int start=0;
   int size=arr.size();
   int end=size-1;
   
  // int mid=start+(end-start)/2;
   while(start<=end){
  int mid=start+(end-start)/2;
    if (arr[mid]==target){
        
        return mid;
    }
    if(arr[mid]>target){
        end=mid-1;
    }
    if(arr[mid]<target){
        start=mid+1;
    }
   
   }
   //yaha tk aagye mtlb element nhi mila
   return -1;

}
int main(){
    vector<int>arr={-1,0,3,5,9,12};
    int target=9;
   // int size=arr.size();
 int index=  search(arr,target);
    if(index!= -1){
        cout<<"Element is present at index "<<index<<endl;

    }
    else{
        cout<<"Not available in array";
    }
}