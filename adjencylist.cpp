#include<iostream>
using namespace std;
#include<list>
#include<unordered_map>

class graph{
    public:
    unordered_map<int,list<int>>adjlist;


void addEdge(int u,int v,bool direc){
    //direc=1
    //undirec=0
    if(direc==0){
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    else{
        adjlist[u].push_back(v);
    }

}
void printAdjlist(){
    for(auto i: adjlist){
        cout<<i.first<<": ";
        cout<<"{";
        for(auto j:i.second){
            cout<<j<<",";
        }
        cout<<"}"<<endl;
    }

}
void printAdjlist1(int n){
    for(int i=0;i<n;i++){
        cout<<i<<":";
        cout<<"{";
        list<int>temp =adjlist[i];
        for (auto j: temp){
            cout<<j<<",";}
            cout<<"}"<<endl;
        
    }
}



};


int main(){
    graph g;
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.printAdjlist1(4);

    return 0;

}