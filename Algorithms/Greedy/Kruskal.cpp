//Name:Dhiraj Sharma
//Email-id:dhirajcoolssharma@gmail.com
// C++ program for Kruskal's algorithm to find Minimum Spanning Tree
#include<bits/stdc++.h>
using namespace std;
//Need to create an undirected weighted and ordered graph.
//Hence write the starting and ending vertices to make an edge,
//this edge has to a weighted edge.
class Edge
{   public:
        int start_vertex;
        int end_vertex;
        int weight;
};
//A comparision function for STL based sorting in increasing order of weight
bool mycomp(Edge e1, Edge e2)
{
    return e1.weight<e2.weight ;
}
/*
// Uninon-find without path compression
//This function provides the start and end vertex parent of an edge
int find(int v, int* parent)
{
    if(parent[v]==v)
        return v;
    return find(parent[v],parent);
}
*/
//Union-Find using path compression
int find(int x, int *parent)
{
    // initially one need to define the root's element to itself as parent[x]=x
    // if an element finds the parent pointing to itself,then root is found    
    if(x == parent[x])
        return parent[x];
    int temp = parent[x];
    // root of x's parent is same with root of x's parent's root
    parent[x] = find(temp,parent);
    return parent[x];
}
//Main function to find MST using Kruskal's Algorithm
//It needs input array,Vertices,Edges of the graph
void kruskalMST(Edge* input, int V, int E)
{	//sorts the input array which is nothing but our undirected weighted edge
    sort(input, input+E, mycomp);
    //Stores Vertices of Graph - 1 in an output edge of type array in sorted order
    Edge* output=new Edge[V-1];
    //Makes a parent array having size of Vertices of Graph
    int* parent=new int[V];
    //Intializes the parent of Vertices of graph
    for(int i=0; i<V; i++)
    {
        parent[i]=i;
    }
    //A counter for checking the equality of start and end vertex parent or cycle.
    int count=0;
    //Used in incrementing the size of sorted array and checks the index 0 value.
    int i=0;
    while(count!=V-1)
    {	//Stores value of sorted array at input index i=0 and picks the smallest weighted edge.
        Edge currEdge=input[i];
        //Stores the parent of current edge, start and end vertices.
        int startparent=find(currEdge.start_vertex,parent);
        int endparent=find(currEdge.end_vertex,parent);
        //checks equality of parent and increments count only when they are not equal
        //if they are not equal it increments the count value first and then
        //combines the start and end vertex parents to form an edge.
        if(startparent!=endparent)
        {
            output[count]=currEdge;
            count++;
            parent[startparent]=endparent;
            
        }
        i++;
    }
    for(int i=0; i<V-1; i++)
	{
    cout <<output[i].start_vertex<<"---- "<<output[i].end_vertex<<"="<<output[i].weight<<endl;
    
	}
}
int main()
{   //Taking input for a graph having V(vertices) and E(edges).
    int V, E;
    cin>>V>>E;  
    //Makes Edge as type of input array
    Edge *input=new Edge[E];    
    for(int i=0;i<E;i++)
    {
        int s,e,w;
        cin>>s>>e>>w;
        input[i].start_vertex=s;
        input[i].end_vertex=e;
        input[i].weight=w;
    }
    //Calling a function to make a KruskalMST
    kruskalMST(input, V, E);  

}
//While taking the input for a graph it will have O(n) complexity since it has a for loop.
//When it goes into the kruskalMST()function the sorting algorithm will have O(n logn) complexity,since there
//is comparsion function which makes it to O(n logn).
//Then the union-find algorithm has a constant time complexity of O(n).
//In displaying the output since there is also a for loop present it has complexity of O(n) too.
//overall time and space complexity is O(n).
//The worst case of Union-Find without path compression is O(n)
//But using path compression it becomes O(logn), as the element which has to searched
//directly becomes the cild of a parent in a weiegted graph
