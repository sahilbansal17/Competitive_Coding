
// Compile in C++11 or higher
#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <climits>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T> > adjList;
public:
       Graph(){}
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

       void topologicalSort(){
       queue<T> q;
       map<T,bool> visited;
       map<T,int> indegree;
       for(auto i:adjList){
        T node = i.first;
        visited[node] = false;
        indegree[node] = 0;
       }
       // Initialize indegrees
       for(auto i: adjList){
        T u = i.first;
        for(T v : adjList[u]){
            indegree[v]++;
        }
       }
       //Find nodes with 0 indegree
       for(auto i:adjList){
        T node = i.first;
        if(indegree[node] ==0){
            q.push(node);
        }
       }
       //Start with algorithm
       while(!q.empty()){
        T node = q.front();
        q.pop();
        cout<<node<<"->";
        for(T neighbour:adjList[node]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                    q.push(neighbour);

            }
        }
       }
       }

};
int main(){
Graph<string> g;
g.addEdge("English","ProgrammingLogic",false);
g.addEdge("Maths","ProgrammingLogic",false);
g.addEdge("ProgrammingLogic","HTML",false);
g.addEdge("ProgrammingLogic","python",false);
g.addEdge("ProgrammingLogic","Java",false);
g.addEdge("ProgrammingLogic","JS",false);
g.addEdge("Python","WebDev",false);
g.addEdge("HTML","CSS",false);
g.addEdge("JS","WebDev",false);
return 0;}
