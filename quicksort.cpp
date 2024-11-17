#include<iostream>
using namespace std;
#include<vector>
void quickSort(vector<int>&v){
int n;
n=v.size();
int small=0;
for(int i=0;i<n;i++){
    for(int j=1;j<n;j++){
        if(v[i]<v[j]){
            small=small+1;

        }
        swap(v[i],v[small+1]);

        if(v[i]>v[j]){
            
        }
    }

    
}

}
printArr(vector<int>&v){
    int size=v.size();
    for(int i=0;i<size;i++){
        cout<<v[i]<<" ";
    }
}


int main(){
vector<int>v={3,1,8,5,2};
quickSort(v);
printArr(v);

}