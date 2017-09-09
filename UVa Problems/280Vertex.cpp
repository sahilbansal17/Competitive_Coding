// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=216

#include <iostream>
#include <vector>
#include <string>
using namespace std;


void dfs(int s, bool visited[], vector<int>adj[],int ct)
{
	if(visited[s])
		return;
	if(ct>0)
	visited[s]=true;
	for(int i=0;i<adj[s].size();i++)
	{
		dfs(adj[s][i],visited,adj,ct+1);
	}
}

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/CP_Sept/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/CP_Sept/output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	while(n!=0)
	{
		vector <int> adj[n+1];
		//vector <int> flag(n+1,0); 
		int i,j;
		cin>>i;
		while(i!=0)
		{
			cin>>j;
			while(j!=0)
			{
				//if(j==i)
				//flag[j]=1;
				adj[i].push_back(j);
				cin>>j;
			}
			cin>>i;
		}
		int check,x;
		cin>>check;
		for(int i=0;i<check;i++)
		{
			int no = 0;
			cin>>x;
			bool visited[n+1];
			for(int j=1;j<=n;j++)
				visited[j]=false;
			dfs(x,visited,adj,no);
			
			//if(flag[x]==0)
			//	visited[x]=false;
			
			int count = 0;
			for(int j=1;j<=n;j++)
			{
				if(visited[j]==false)
					count++;
			}
			cout<<count;
			if(count>0)
				cout<<" ";
			for(int j=1;j<=n;j++)
			{
				if(visited[j]==false)
				{
					count--;
					cout<<j;
					if(count>0)
						cout<<" ";
				}
			}
			cout<<endl;
		}

		cin>>n;
	}

	return 0;
}