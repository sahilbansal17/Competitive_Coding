#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

class Graph
{
    int V;
    
    list<int> *adj;
 
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V); 
    void addEdge(int v, int w);
    void connectedComponents();
};
 
vector<int> vv;
vector<pair<int,int> > vvv;
void Graph::connectedComponents()
{
    bool *visited = new bool[V];
    for(int v = 0; v < V; v++)
        visited[v] = false;
 
    for (int v=0; v<V; v++)
    {
        if (visited[v] == false)
        {
            vv.clear();
            DFSUtil(v, visited);
 			if(vv.size()==1)
 			{				
			}
			else
			{
				for(int j=1;j<vv.size();j++)
			 	{
			 		vvv.push_back(make_pair(vv[j],vv[0]));
				}
			}
        }
    }
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    vv.push_back(v);
 
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 
int main()
{    
	Graph g(26);
	int n,i,j;
   	cin>>n;
   	string a,b;
   	cin>>a>>b;
   	int arr[26][26];
   	for(i=0;i<26;i++)
   	for(j=0;j<26;j++)
   	arr[i][j]=0;
   
   	for(i=0;i<n;i++)
   	{
   		if(a[i]!=b[i])
   		{
   			arr[a[i]-'a'][b[i]-'a']=1;
	   		arr[b[i]-'a'][a[i]-'a']=1;
	   }
    }	
   
    for(i=0;i<26;i++)
    {
   		for(j=0;j<26;j++)
   		{
   			if(arr[i][j]==1)
   			{
   				g.addEdge(i, j);
   				arr[j][i]=0;
		   }
	   }
   }
   
   	g.connectedComponents();
 	cout<<vvv.size()<<endl;
 	for(i=0;i<vvv.size();i++)
 	{
 		cout<<char(vvv[i].first+'a')<<" "<<char(vvv[i].second+'a')<<endl;
	}
    return 0;
}
