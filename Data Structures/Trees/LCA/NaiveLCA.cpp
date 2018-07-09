// This program finds LCA of two nodes in a rooted tree.

#include <iostream>
#include <vector>

using namespace std;

const int L = 1e5+7;
std::vector<int> v[L];
int v1, v2, LCA;

int findLCA(int vertex,int parent)
{
	// counter to check the number of nodes out of the v1 and v2 which exist in 
	// current node's subtree
	int counter = 0;
	// current node is equal to one of the query nodes
	if(vertex == v1 || vertex == v2)
	{
		counter++;
	}
	for(auto &x:v[vertex])
	{
		if(x != parent)
		{
			counter += findLCA(x, vertex);
		}
	}
	// If both v1 and v2 exist in current node's subtree then set LCA = current node
	// The current node is the lowest out of all the common ancestors of the query nodes as it is the 
	// first node encountered in the dfs tree which has both v1 and v2 in its subtree, so it would be the LCA. 
	// To avoid further update of LCA value we return 0 instead of counter. There won't be any further update of 
	// the LCA value as this was the only subtree which could have returned 2 and instead of returning 2 we have 
	// returned 0 from here.
	
	if(counter == 2)
	{
		LCA = vertex;
		return 0;
	}
	else 
	{
		return counter;
	}
}
int main()
{
	int queries, number_of_nodes;
	cout << "Enter number of nodes -> ";
	cin >> number_of_nodes;

	cout << "Enter edges->" <<endl;

	// Building the tree
	for (int i = 0; i < number_of_nodes-1; ++i)
	{
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}
	cout << "Enter number of queries->";
	cin >> queries;

	while( queries-- )
	{
		cout << "Enter vertices -> " ;
		cin >> v1 >> v2;
		findLCA(1, -1);
		cout << "LCA of "<< v1 <<" and "<< v2 <<" is "<< LCA <<endl;
	}
	return 0;
}
// In this algorithm we start dfs from the root and find the lowest node which has both the nodes v1 and v2
// in its subtree. In the dfs tree the first node i.e. the node at lowest depth which has both the nodes v1 and v2 
// in its subtree would be the LCA.

// Time complexity : Per query -> O(n)
// 				  	Each query requires a dfs traversal. The completexity of dfs is O(V+E). For a tree E = n-1.
// 				  	So complexity of dfs is O(n).
// Space Complexity : O(n)
// 				  	Required for storing the input