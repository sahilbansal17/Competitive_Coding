#include<bits/stdc++.h>
using namespace std;

/** The following problem can be divided into following cases:
    1. When number of edges is even the you don't need to group any vertices or all
       vertices can be considered in one group.
    
    2. When number of edges is odd and there is one vertex which when removed or
      when its edges are subtracted from total edges the number of edges come out to
      be even. Thus we get will get two groups one with reduced vertex having even edges
      and one left out with zero edges.

    3. Last case is when number of edges is odd and we can't find that one vertex, or
        there is no vertex with odd number of edges ( as Odd-Odd = Even). Here we try
        to find a neighbour of an vertex which is also having odd edge thus when we remove
        both vertex the number of edges is odd (even + even -1 = odd where 1 is the comman
        edge subtracted). Thus we get three groups one with each removed vertex and the last
        one with reduced vertex.

    We cannot find any other possiblity , thus k can only take values 1,2,3
  **/


int main(){
    // faster IO
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // take input
    int t;
    cin>>t;
    while(t--)
    {
        // take number of vertices and edges as input
        int n,m;
        cin>>n>>m;
        // Create an adjacency list of size n to store the adjacent edge to each vertex 
        vector<int>* Edges = new vector<int>[n];

        //Create a array to keep track of total number of graph
        int* Graph = new int[n]();

        // loop to update the list
        for(int i=0;i<m;i++)
        {
            int s,f;
            cin>>s>>f; // take two adjacent vertex s,f
            Edges[s-1].push_back(f-1); // push vertex f-1 to list s-1
            Edges[f-1].push_back(s-1); // vice-versa
            Graph[s-1] ++; // update count of vertices
            Graph[f-1] ++;
        }
        // The answer array stores the group in which we group the array
        int* ans = new int[n](); 

        //Case 1 grouping all vertex in same group
        if(m%2==0)
        {
            cout<<1<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<ans[i]+1<<" "; // printing ans+1 since I have taken indexing from zero
            }
            cout<<endl;
            continue;
        }
        // Case 2
        bool flag=false; // a flag to check whether we are able to group vertices
        int k=2; // declare k=2 for case 2
        for(int i=0;i<n;i++)  // loop for all vertices
        {
            if((m-Graph[i])%2==0) // and check whether removal makes even edges
            {
                ans[i]++; // update the group no. of removed vertex
                cout<<k<<endl;
                for(int i=0;i<n;i++)
                {
                cout<<ans[i]+1<<" "; // print groups
                }
                cout<<endl;
                flag=true; // make flag true to specify that we found a group
                break; // then break out of loop
            }
        }
        if(flag) continue; // continue no need to check other cases
        // Case 3 k=3
        k=3;
        for(int i=0;i<n;i++) // loop for all vertices
        {
            for(int j=0;j<Edges[i].size();j++) // check its neighbours 
            {
                if((m-Graph[i]-Graph[Edges[i][j]] + 1)%2==0) // if removal makes it even
                {
                    ans[i]+=2; // make one in group 3 (adding 2)
                    ans[Edges[i][j]]++; // other in group 2
                    cout<<k<<endl;  
                    for(int i=0;i<n;i++)
                    {
                    cout<<ans[i]+1<<" "; // print groups
                    }
                    cout<<endl;
                    flag=true; // make flag true to specify we find a group
                    break;  // break out of loop if we find only one such pair
                }
            }
            if(flag) break; // break out if flag is true
        }
    }
    
    return 0;
}
