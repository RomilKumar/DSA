#include<iostream>
using namespace std;
#include<vector>
void print(vector<int>v){
 int size=v.size();
 for(int i=0;i<size;i++){
    cout<<v[i]<<" ";
 }
cout<<endl;
}


void bubble(vector<int>&v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            //for decreasing order reverse>sign
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
             
        }
    }
}


int main(){
vector<int>v={6,4,5,3,2,1};
bubble(v);
print(v);



    return 0;
}