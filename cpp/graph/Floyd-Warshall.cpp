//Implemented Floyd-Warshall algo. Complexity O(n^3)
//Problem link - https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0
#include<iostream>
using namespace std;
int main() {
	int t,v,i,k,j;
	cin>>t;
	while(t--)
	{
	    cin>>v;
	    int ad[v][v]; 
	    for(i=0;i<v;i++)
	    {
	        for(j=0;j<v;j++)
	        {
	            cin>>ad[i][j]; //Build the adjacency matrix
	        }
	    }
	    
	    for(k=0;k<v;k++)
	    {
	        for(i=0;i<v;i++)
	        {
	            for(j=0;j<v;j++)
	            {
	                if(ad[i][k]!=10000000 && ad[k][j]!=10000000 &&
	                ad[i][k]+ad[k][j]<ad[i][j]) // Find the shortest distance between i and j via k.
	                ad[i][j]=ad[i][k]+ad[k][j];
	            }
	        }
	    }
	    
	    for(i=0;i<v;i++)
	    {
	        for(j=0;j<v;j++)
	        {
	            if(ad[i][j]!=10000000)
	            cout<<ad[i][j]<<" ";
	            else
	            cout<<"INF"<<" "; // print INF if it contains 1e7
	        }
	        cout<<"\n";
	    }
	    
	    
	    
	}
	return 0;
}