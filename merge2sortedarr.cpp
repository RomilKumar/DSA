#include<iostream>
#include<vector>
using namespace std;
bool solve(int arr[],int arrsize,int brr[],int brrsize,vector<int>&ans)
{
    int i=0;
    int j=0;
    //jb tk index se bahr n nikal jao compare karke pushback karo
    while(i<arrsize&&j<brrsize){
        if(arr[i]>brr[j]){
            ans.push_back(brr[j]);
            j++;
        }
        else{ 
            ans.push_back(arr[i]);
            i++;
        }
    }
    //2 case or hoskte h yaa to pehle wale ke element khtm hojaye ya dusre
    while(i<arrsize){
        ans.push_back(arr[i]);
        i++;
    }
    while(j<brrsize){
        ans.push_back(brr[j]);
        j++;
    }
}
int main(){
    int arr[]={10,30,50,70};
    int arrsize=4;
    int brr[]={20,40,60,80,90,100};
    int brrsize=6;
    //is vector me ans store karana end me merge kara ke
    vector<int>ans;
    solve(arr,arrsize,brr,brrsize,ans);
    for(int nums:ans){
        cout<<nums<<" ";
    }
    return 0;
}
