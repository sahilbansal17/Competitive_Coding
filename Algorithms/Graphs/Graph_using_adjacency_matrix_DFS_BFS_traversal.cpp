//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is the implementation of graph using adjacency matrix
//with DFS and BFS traversal
#include<iostream>
#include<queue>
using namespace std;

//this is a helper function to DFS() function
void printDFS(int **edges,int n,int sv,bool *visited){
	//firt printing the starting vertices
	cout<<sv<<endl;
	//and making th printed element as true so that printed only once
	visited[sv] = true;
	//iterate over all the elements to print the whole graph
	for(int i=0;i<n;i++){
		if(i==sv){
			continue;
		}
		if(edges[sv][i]==1){
			if(visited[i]){
				continue;
			}
			//calling recursion
			printDFS(edges,n,i,visited);
		}
	}
}

//DFS function prints the DFS traversal
void DFS(int** edge,int n){
	//visited array is used to check if aalready printed or not
	//if already printed than not printed 
	bool* visited = new bool[n];
	//initializing the array with false
	for(int i=0;i<n;i++){
		visited[i] = false;
	}
	//calling helper function,this looping is necessasry for discontinue graph
	for(int i=0;i<n;i++){
		if(!visited[i]){
			printDFS(edge,n,i,visited);
		}
	}
	//freeup memory
	delete [] visited;
}

//this is a helper function to BFS() function
void printBFS(int **edges,int n,int sv,bool *visited){
	//using queue to print the graph level wise
	queue<int>pendingVertices;
	//pushing the element to queue 
	pendingVertices.push(sv);
	visited[sv] =true;
	//iterating over the pending vertices
	while(!pendingVertices.empty()){
		//taking the element to be printed in currentVertex
		//and poping it out
		int currentVertex = pendingVertices.front();
		pendingVertices.pop();
		//printing the first element 
		cout<<currentVertex<<endl;
		//iterating over to print all the elements
		for(int i=0;i<n;i++){
			if(i==currentVertex){
				continue;
			}
			if(edges[currentVertex][i] == 1 && !visited[i]){
				pendingVertices.push(i);
				visited[i] =true;
			}
		}
	}
}
//DFS function prints the BFS traversal
void BFS(int** edge,int n){
	//visited array is used to check if aalready printed or not
	//if already printed than not printed 
	bool* visited = new bool[n];
	//initializing the array with false
	for(int i=0;i<n;i++){
		visited[i] = false;
	}
	//calling helper function,this looping is necessasry for discontinue graph
	for(int i=0;i<n;i++){
		if(!visited[i]){
			printBFS(edge,n,i,visited);
		}
	}
	//freeup memory
	delete [] visited;
}

//main function that drives the program
int main()
{
	//n is number of vertices and e is number of edges
	int n;
	int e;
	cout<<"Enter the number of vertices : ";
	cin>>n;
	cout<<"Enter the number if Edges : ";
	cin>>e;
	//edges is a 2d adjacency matrix 
	int **edges = new int*[n];
	for(int i=0;i<n;i++){
		edges[i] = new int[n];
		for(int j=0;j<n;j++){
			edges[i][j] = 0;
		}
	}
	
	cout<<"Enter the connecton be/w the vertices :"<<endl;
	for(int i=0;i<e;i++){
		int f,s;
		cin>>f>>s;
		
		edges[f][s] = 1;
		edges[s][f] = 1;
	}

	cout<<"DFS traversal is as follows : "<<endl;
	DFS(edges,n);
	cout<<"BFS traversal s as follows : "<<endl;
	BFS(edges,n);
	
	//freeing up of the memory
	for(int i=0;i<n;i++){
		delete[]edges;
	}
	delete[]edges;
}
