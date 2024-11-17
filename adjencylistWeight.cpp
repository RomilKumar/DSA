#include<iostream>
using namespace std;
#include<list>
#include<unordered_map>
class graph{
    public:
    unordered_map<int,list<pair<int,int>>>adjlist;

void addEdge(int u,int v,int wt,bool direc){

    if(direc==0){
adjlist[u].push_back({v,wt});
adjlist[v].push_back({u,wt});

    }
    else{
        adjlist[u].push_back({v,wt});

    }

}
void printlist(int n){
    {
    for(int i=0;i<n;i++){
        cout<<i<<":";
        cout<<"{";
        list< pair<int,int>>temp =adjlist[i];
        for (auto j: temp){
            cout<< "("<<j.first<<","<<j.second<<")";
            }
            cout<<"}"<<endl;
        
    }
}

}
};
int main(){
graph g;
g.addEdge(0,1,3,1);
g.addEdge(0,2,4,1);
g.addEdge(1,2,1,1);
g.addEdge(2,3,16,1);
g.printlist(4);


    return 0;
}