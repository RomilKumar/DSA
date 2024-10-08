#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
void nextSmaller(int arr[], stack<int>&st,vector<int>&ans){
int n=5;
st.push(-1);
 for(int i=n-1;i>=0;i--){
    int element=arr[i];

    while(st.top()>element){
        st.pop();
    }
    ans.push_back(st.top());
    st.push(element);
 }

}

int main(){
    int arr[]={4,8,5,2,25};
        stack<int>st;
        vector<int>ans;

        nextSmaller(arr,st,ans);


       // reverse(ans.begin(),ans.end());

    for (int x : ans) {
        cout << x << " ";
    }

return 0;

}