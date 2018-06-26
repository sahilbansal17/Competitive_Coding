
/*  The following is an implementation of Prim's algorithm
    using adjacency list representation of a graph. The data structure
    min heap is used for this. There are, again, two implementations
    in this, the min heap code can be written differently in a class, or
    the priority_queue present in STL can be used. Here, it's the
    latter.
    Now, a priority_queue is essentially a max heap, but can be used
    as given below to form a min heap. The loop statements execute
    v+e times, in addition to log(v) time for adding to priority_queue.
    Overall, O(v+e)*O(log(v)) = O((e+v)*log(v)) = O(e*log(v))
    Since for a connected graph, v = O(e).
*/

#include<bits/stdc++.h>
#define INF INT_MAX

using namespace std;

int main(){
    cout<<"Enter number of vertices of the graph"<<endl;
    int v;
    cin>>v;

    vector<pair<int, int> > adj[v];
    int i, j; //Iterators

    cout<<"Enter number of edges of the graph"<<endl;
    int e;
    cin>>e;

    cout<<"Enter the vertices and their edge weights in the following format :"<<endl;
    cout<<"Vertex1 Vertex2 Weight"<<endl;
    cout<<"PS : First vertex should be 0."<<endl;

    for (i = 0; i < e; i ++){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        adj[v1].push_back(make_pair(w,v2));
        adj[v2].push_back(make_pair(w,v1));
    }

    int mst[v];
    //Array to store MST
    int keys[v];
    //Key values of every edge
    bool included[v];
    //The corresponding vertex has already been included if true

    for (i = 0; i < v; i ++){
        mst[i] = -1;
        keys[i] = INT_MAX;
        //Set all key values to infinity
        included[i] = false;
        //None of the vertices have been included yet
    }

    int f = 0;
    int s;

    priority_queue< pair<int,int> , vector<pair<int,int> > , greater< pair<int,int> > > Q;
    //Priority queue as a minHeap
    pair<int,int> p;

    mst[0] = 0;
    Q.push(make_pair(0,0));
    //To start MST with node 0, the root node

    while(!Q.empty()){

        p = Q.top();
        f = p.second;
        //Edge with minimum weight is selected
        Q.pop();

        for(int i = 0;i < adj[f].size(); ++ i){
            int v = adj[f][i].second;
            int weight = adj[f][i].first;

            if (!included[v] && keys[v] > weight){
                keys[v] = weight;
                Q.push(adj[f][i]);
                mst[v] = f;
            }
        }
    }

    cout<<"Minimum spanning tree has been generated."<<endl;

    for(i = 1; i < v; ++i){
        cout<< mst[i] <<" ";
    }
    return 0;
}
