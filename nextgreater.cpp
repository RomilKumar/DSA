#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

 void nextGreatest(vector<int>&arr,int n,vector<int>&ans){
    stack<int>s;
    s.push(-1);
    for(int i=n-1;i>=0;i--){
        int element=arr[i];

        while((s.top()!=-1)&&s.top()<= element){
s.pop();

        }

            ans.push_back(s.top());
    s.push(element);
 }
    }




int main(){
   vector<int> arr = {6, 0, 8, 1, 3}; 

        vector<int>ans;
        int n=arr.size();

        nextGreatest(arr,n,ans);
reverse(ans.begin(),ans.end());
            for (int x : ans) {
        cout << x << " ";
    }
return 0;



}