#include<iostream>
using namespace std;
int main(){
    int arr[]={5,4,3,2,1};
     int n=5;
    for(int i=1;i<n;i++){
       int  key=arr[i];
       int j=i-1;
//key me pehle wale ko chhod ke dusra chala gya
//j ko pehle pe shift kardiya

    
    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    //ise pehle wale pe desired elemrnt chala jayega
    arr[j+1]=key;
    
    }
    for (int i=0;i<n;i++)
{
    cout<<arr[i]<<" ";
}


    return 0;
}