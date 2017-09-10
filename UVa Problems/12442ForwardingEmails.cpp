// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3873


/*algorithm
1. make the adjacency list
2. make an array which stores the no of martians to whom email can be sent
from ith martian
3. fill the array by performing dfs from each martian
4. find the max value of the array occuring at the lowest index
*/

/*Improved algo in terms of space complexity:
instead of doing 2 and 3 in earlier algo, just take a max=INT_MIN as the max possible
emails that can be seen and if in dfs of ith node you encounter strictly larger value
than the previous max, update the max and set the value whom_to_send as that ith node

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int dfs(int s, bool visited[], vector<int>adj[])
{
	int count = 1;
	if(visited[s])
		return 0;
	visited[s]=true;
	for(int i=0;i<adj[s].size();i++)
	{
		count += dfs(adj[s][i],visited,adj); 

		//at each level it adds 1 to the count, so finally it returns max level in the graph
	}
	return count;
}

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/CP_Sept/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/CP_Sept/output.txt","w",stdout);
	#endif

	int t,n;
	cin>>t;

	int case_no = 1;
	while(case_no<=t)
	{
		cin>>n;
		vector <int> adj[n+1];
		
		int x,y; //x can send an email to y
		for(int i=0;i<n;i++)
		{
			cin>>x>>y;
			adj[x].push_back(y);
		}

		int max=INT_MIN,whom_to_send;
		for(int i=1;i<=n;i++)
		{
			int no; //total no of emails which can be sent if ith martian is sent an email
			bool visited[n+1];
			for(int j=1;j<=n;j++)
				visited[j]=false;
			no = dfs(i,visited,adj); //count the no of mails that can be sent if dfs done from ith
			if(no>max) //strict inequality makes sure that in case of more than one max, it output the node which is least numbered
			{
				max = no;
				whom_to_send = i;
			}
			//cout<<no<<" ";  just for purpose of debugging
		}
		//cout<<endl;
		cout<<"Case "<<case_no<<": "<<whom_to_send<<endl;
		case_no++;
	}

	return 0;
}