#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
void prevsmaller(vector<int>&v,vector<int>&ans){
int n=v.size();
stack<int>s;
s.push(-1);

for(int i=0;i<n;i++){
    int element=v[i];

    while(s.top()>element){
        s.pop();
    }
    ans.push_back(s.top());
    s.push(element);
}
}


int main(){
vector<int>v;
v.push_back(8);
v.push_back(4);
v.push_back(2);
v.push_back(6);
v.push_back(3);


vector<int>ans;
 prevsmaller(v,ans);

 for(int x:ans){
    cout<<x<<" ";
 }


}