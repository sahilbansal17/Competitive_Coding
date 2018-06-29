/* The following program represents the Prim's algorithm
for finding the Minimum Spanning Tree of a graph represented
as an adjacency matrix (2d matrix).

The time complexity of this algorithm is O(v^2), where
v is the number of vertices, since adjacent vertices of each
vertex are being iterated through (v*v).

*/

#include<bits/stdc++.h>

using namespace std;

int findMin( int* keys, bool* included, int v){
    int mini = INT_MAX;
    int index;
    int i;

    for( i = 0; i < v; i ++){
        if( !included[i] && keys[i] < mini){
            mini = keys[i];
            index = i;
        }
    }
    return index;
}

int main(){
    cout<<"Enter number of vertices of the graph"<<endl;
    int v;
    cin>>v;

    int graph[v][v];
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
        graph[v1][v2] = w;
    }

    int mst[v];
    //Array to store MST
    int keys[v];
    //Key values of every edge
    bool included[v];
    //The corresponding vertex has already been included if true

    for (i = 0; i < v; i ++){
        keys[i] = INT_MAX;
        //Set all key values to infinity
        included[i] = false;
        //None of the vertices have been included yet
    }

    keys[0] = 0;
    mst[0] = -1;
    //So that first vertex is picked first, it's the root for an MST

    for(i = 0; i < v-1; i ++){
       int minKey = findMin( keys, included, v);
       //The index of the vertex with the least key value

       included[minKey] = true;

       for(j = 0; j < v; j ++){
            if ( !included[j] && graph[minKey][j] && graph[minKey][j] < keys[j]){
                mst[j] = minKey;
                keys[j] = graph[minKey][j];
            }
       }
    }

    cout<<"Minimum spanning tree has been generated."<<endl;

    for(i = 0; i < v; i ++){
        cout<< mst[i] <<" to "<<i<<" weighs "<< graph[i][mst[i]] <<endl;
    }
    return 0;
}