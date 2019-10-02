#include<bits/stdc++.h>
using namespace std;

//To generate the stack in decreasing order of finish time
void DFS(vector<int> graph[], int u, vector<bool> &visited, stack<int> &st)
{
	visited[u]=1;
	for(int i=0;i<graph[u].size();i++)
	{
		int v=graph[u][i];
		if(visited[v])
			continue;
		DFS(graph,v,visited,st);
	}
	//vertex is pushed into the stack after all its childer are visited.
	st.push(u);
}

//DFS on the transpose graph to generate strongly connected component
void DFS_transpose(vector<int> graph_transpose[], int u, vector<bool> &visited, vector<int> & component)
{
	visited[u]=1;
	component.push_back(u);
	for(int i=0;i<graph_transpose[u].size();i++)
	{
		int v=graph_transpose[u][i];
		if(visited[v])
			continue;
		DFS_transpose(graph_transpose,v,visited,component);
	}
}

int main()
{
	//Vertices of the graph are numbered from 0 to V-1
	int v,e;
	cin>>v>>e;
	vector<int> graph[v];
	//transpose graph consists of all the vertices of the graph with every edge's direction reversed.
	vector<int> graph_transpose[v];

	for(int i=0;i<e;i++)
	{
		int src,dest;
		cin>>src>>dest;
		graph[src].push_back(dest);
		graph_transpose[dest].push_back(src); //reverse edge is pushed in transpose graph
	}
	
	//stack stores all vertices in decreasing order of finish time.
	//Top of the stack is the element whose processing in the DFS finishes last.
	stack<int> st;
	vector<bool> visited(v);

	for(int i=0;i<v;i++)
	{
		if(visited[i])
			continue;
		DFS(graph,i,visited,st);
	}
	//Stores all the strongly connected components.
	vector<vector<int> > scc;

	//reinitialise visited vector
	for(int i=0;i<v;i++)
		visited[i]=0;

	while(st.size()>0)
	{
		int u=st.top();
		st.pop();
		if(visited[u])
			continue;
		vector<int> component;
		//get the component with the u'th vertex as a part
		DFS_transpose(graph_transpose,u,visited,component);
		scc.push_back(component);
	}

	//printing all strongly connected components
	for(int i=0;i<scc.size();i++)
	{
		cout<<"component "<<i+1<<": ";
		for(int j=0;j<scc[i].size();j++)
			cout<<scc[i][j]<<" ";
		cout<<endl;
	}
}