#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
int V;
list<pair<int,int> > * adjlist;
Graph(int nodeCount)
{
    V=nodeCount;
    adjlist=new list<pair<int,int> >[V];
}
void addEdge(int u ,int v,int dist){
    adjlist[u].push_back(*(new pair<int,int>(v,dist)));
}

};

int Dijikstra(Graph graph,int source)
{
int* dist=new int[graph.V];
for(int i=0;i<graph.V;i++)
{
    dist[i]=INT_MAX;
}
dist[source]=0;
bool* visited= new bool[graph.V];
for (int i = 0; i < graph.V; ++i)
{
    visited[i]=false;
}
visited[source]=true;

int node=source;
int minNode=0;

while(minNode!=-1){
for(auto ele:graph.adjlist[node]){
    if(!visited[ele.first])
    {
        if(dist[node]+ele.second<dist[ele.first]){
            dist[ele.first]=dist[node]+ele.second;
        }
    }
}
    int min=INT_MAX;
    minNode=-1;
    for(int j=0;j<graph.V;j++){
        
         
        if(!visited[j]==true && dist[j]<min){
            min=dist[j];
            minNode=j;
        }
    }
    if(minNode!=-1)
    {node=minNode;
    visited[node]=true;}
}

for (int i = 0; i < graph.V; ++i)
{
    cout<<"distance between "<<source<<" and "<<i<<"-->"<<dist[i]<<endl;
}

return 0;
}


int main(){
int noOfNodes=0;
cout<<"enter no of nodes for graph"<<endl;
cin>>noOfNodes;
Graph graph(noOfNodes);
int firstNode,secondNode,distance=0;
for(int i=0;i<noOfNodes;i++){
cout<<"enter edge of graph and its weight"<<endl;
cin>>firstNode>>secondNode>>distance;
graph.addEdge(firstNode,secondNode,distance);
}
int sourceNode=0;
cout<<"enter starting/source node from which we have to calculate minimum distance to all other nodes"<<endl;
cin>>sourceNode;
Dijikstra(graph,sourceNode);
return 0;
}
