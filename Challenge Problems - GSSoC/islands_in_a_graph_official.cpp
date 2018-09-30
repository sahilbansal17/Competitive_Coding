#include <bits/stdc++.h>
using namespace std;

//ALGORITHM: Find the smallest k lakes and fill these and the answer is the sum of components of the island.
//Must check if lake is connected to a boundary, thus more conditions in floodfill dfs algorithms.
//checklake and floodfill use dfs

#define maxN 52
char a[maxN][maxN];//main input
int visited[maxN][maxN];//to check if a cell is visited; change to bool to save memory
int mark[maxN][maxN];//to mark a cell, similar to visited;^^
bool lake;//to check if a lake exists and isn't connected to the ocean.
int numadj,n,m;//numadj is the number of components in the island, cells in an island.
vector < pair <int, pair <int,int> > > v;//vector storing numadj and the co-ordinates of any point in the lake from which flood filling begins
void checklake(int x,int y)//to check if lake is valid
{   if(x<0||x>=n||y<0||y>=m)//if in any further calls we go completely out of bound, get out of checklake and return nothing. Due to lower if, lake will be false in any case.
    return;
    visited[x][y]=1;//mark point as visited
    numadj++;//1 component in lake added.
    if(x==0||x==n-1||y==m-1||y==0)//if we are at any boundary, that means lake is touching the ocean, and don't count it.
    {
        lake=false;
    }
    //check all 4 neighbours similarly if they are .(water) and if they're not previously visited. if we don't check if previously visited, function will go into infinite recursive calls.
    if(!visited[x][y+1]&&a[x][y+1]=='.')checklake(x,y+1);
    if(!visited[x][y-1]&&a[x][y-1]=='.')checklake(x,y-1);
    if(!visited[x+1][y]&&a[x+1][y]=='.')checklake(x+1,y);
    if(!visited[x-1][y]&&a[x-1][y]=='.')checklake(x-1,y);
}

void ffill(int x,int y)//at the end, filling the smallest islands
{   //This is a textbook flood fill algorithm.
    a[x][y]='*';//mark/fill current cell
    mark[x][y]=1;//mark as visited. using just 1 array visited/mark for same purpose SHOULD also work, haven't checked yet.
    if(a[x][y+1]=='.'&&!mark[x][y+1])ffill(x,y+1);//flood fill calls
    if(a[x][y-1]=='.'&&!mark[x][y-1])ffill(x,y-1);
    if(a[x+1][y]=='.'&&!mark[x+1][y])ffill(x+1,y);
    if(a[x-1][y]=='.'&&!mark[x-1][y])ffill(x-1,y);
}
int main() {
    std::ios::sync_with_stdio(false);
	int k,ans=0;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<m;j++)
	    { 
	        cin>>a[i][j];
	       
	    }
	}
		for(int i=0;i<n;i++)//accomodate in upper for loop, simple initialisation
	{
	    for(int j=0;j<m;j++)
	    { 
	        
	       visited[i][j]=0;
	        mark[i][j]=0;
	    }
	}
	 
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<m;j++)//for every cell
	    {   numadj=0;//initialise
	        if(a[i][j]=='.'&&!visited[i][j])//if we get a start point, lets check lake
	        {   lake=true;//initialise
	            checklake(i,j);//checklake function call with those co-ordinates
	            
	            if(lake)
	            {
	                v.push_back({numadj,{i,j}});//push in vector if valid lake
	            }
	        }
	    }
	}
	sort(v.begin(),v.end());//vector consists of all valid lakes. Sorts lakes by their size.
	
	for(int i=0;i<v.size()-k;i++)//smallest k lakes will be counted and filled
	{
	    ans+=v[i].first;//direct sum computation
	    ffill(v[i].second.first,v[i].second.second);//fill using flood fill
	}
	cout<<ans<<endl;
		for(int i=0;i<n;i++)
	{
	    for(int j=0;j<m;j++)
	    { 
	        cout<<a[i][j];
	    }
	    cout<<endl;
	}
	return 0;
}
