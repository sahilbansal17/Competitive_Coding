//use c++11 or higher
//Don't try to run on code blocks
#include <iostream>
#include <map>
#include <list>
using namespace std;

template<typename T>
class Graph{
    map<T , list<T> > adjList;

public :
    Graph(){
    }
    void addEdge(T u,T v,bool bidir = true){
       adjList[u].push_back(v);
       if(bidir){
        adjList[v].push_back(u);
       }
       }
       void print(){
       //Iteration
       for(auto i:adjList){
        cout<<i.first<<"->";
        //i.second is LL
        for(T entry:i.second){
            cout<<entry<<",";
        }
        cout<<endl;
       }
       }
       void dfsHelper( T node, map<T,bool> &visited){
       //Whenever to come to a node mark it visited
       visited[node] = true;
       cout<<node<<" ";
       //TRY TO find out neighbour node which is not visited yet
       for(T neighbour: adjList[node]){
        if(!visited[neighbour]){
            dfsHelper(neighbour,visited);
        }
       }
       }
      void dfs( T src){
       map<T,bool> visited;
       dfsHelper(src,visited);
      }


};
int main(){
   Graph<int> g;
   g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(0,4);
g.addEdge(2,4);
g.addEdge(2,3);
g.addEdge(3,5);
g.addEdge(3,4);
g.dfs(0);
return 0;
}
