// This program finds LCA of two nodes in a rooted tree using Binary Lifting

#include <iostream>
#include <vector>

using namespace std;

const int L = 1e5+7;
std::vector<int> v[L];
int parent[L][22], level[L];
void dfs(int vertex, int prev_node)
{
	// assigning depth of current node wrt root
	level[vertex] = level[prev_node] + 1;

	// immediate parent in the dfs tree is the 2^0th = 1st ancestor 
	parent[vertex][0] = prev_node;
	for(auto &x : v[vertex])
	{
		if(x != prev_node)
		{
			dfs(x, vertex);
		}
	}
}
int findLCA(int v1, int v2)
{
	if(level[v1] > level[v2])
	{
		swap(v1, v2);
	}
	// if both nodes are not at same level then bring them at same level 
	int dist = level[v2] - level[v1];
	for (int i = 0; i < 22; ++i)
	{
		if(dist & 1)
		{
			v2 = parent[v2][i]; 
		}
		dist >>= 1;
	}
	// if v2's ancestor on the same level as v1 is v1 it means that v1 lies in the
	// path from v2 to the root and hence the LCA of v1 and v2 is v1
	if( v1 == v2 )return v1;

	for (int i = 21; i >= 0; --i)
	{
		// Jump higher only if the 2^i th ancestor of both the nodes are not the same. This is done because 
		// the nodes in the path from the LCA to the root are all common ancestors of the 2 nodes and if 
		// we need to reach the LCA we should avoid jumping to a node at a higher level than the LCA. 
		// This condition helps us avoid it. Ultimately we reach a node which is the 1st child of 
		// LCA and then it's easy to get the LCA as it would be the 2^0 th ancestor of the node. 
		if(parent[v1][i] != parent[v2][i])
		{
			v1 = parent[v1][i];
			v2 = parent[v2][i];
		}
	}
	return parent[v1][0];
}
int main()
{
	int queries, v1, v2, LCA, number_of_nodes;
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

	// initializing the parent array
	for (int i = 1; i <= number_of_nodes; ++i)
	{
		for (int j = 0; j < 22; ++j)
		{
			parent[i][j] = -1;
		}
	}

	// dfs to find immediate parent of each vertex and assigning depth of each vertex wrt root
	dfs(1, 0);

	for (int j = 1; j < 22; ++j)
	{
		for (int i = 1; i <= number_of_nodes ; ++i)
		{
			// We combine Dynamic Programming and Divide & Conquer here. The path from a node to
			// its 2^j th ancestor can be divided into 2 parts, path from node to its 2^(j-1)th ancestor
			// and path from 2^(j-1)th ancestor to its 2^(j-1)th ancestor. So the 2^j th ancestor of
			// a node i would be the 2^(j-1) th ancestor of its 2^(j-1)th ancestor
			if(parent[i][j-1] != -1)
			{
				parent[i][j] = parent[ parent[i][j-1] ][j-1];
			}
		}
	}
	cout << "Enter number of queries->";
	cin >> queries;

	while( queries-- )
	{
		cout << "Enter vertices -> " ;
		cin >> v1 >> v2;
		LCA = findLCA(v1, v2);
		cout << "LCA of "<< v1 <<" and "<< v2 <<" is "<< LCA <<endl;
	}
	return 0;
}

// The basic idea behind this algorithm is that any natural number can be represented as a sum of distinct
// powers of 2. There are many ways to prove it. Let's prove this by induction.
// P(n) : n can be represented as sum of distinct powers of two.
// P(1) is true as 1 = 2^0

// Induction hypothesis : Assume P(k) is true for all k which satisfies 0 <= k <= n.

// Consider the largest power of 2 less than or equal to n+1 as 2^m. Now consider the number n + 1 - 2^m. 
// 2^m >= 1 -> n + 1 - 2^m <= n. From our induction hypothesis we can say that n + 1 - 2^m can be represented 
// as sum of distinct power of 2. Let the set of these numbers be S. If we somehow prove that 2^m doesn't 
// belong to this set S then it would mean that n + 1 can be represented as sum of distinct power of 2. 

// We prove  this by contradiction. Assume 2^m belongs to S. If 2^m belongs to S then n + 1 - 2^m must be greater 
// than or equal to 2^m. n + 1 -2^m >= 2^m => n + 1 >= 2^(m+1) . So the highest power of 2 which is less than or 
// equal to n+1 is 2^(m+1) which is a contradiction as we have assumed that the highest power of 2 less than n+1 
// is 2^m. So P(n+1) is true. 
// Hence from the principle of strong induction we can say that P(n) is true for all n >= 1.

// Another way of seeing it is that suppose that the ith, jth, kth bit of binary representation of a number is 1 
// then the number can be written as 2^i + 2^j + 2^k. 
// eg -> 12 = 1100 = 2^3 + 2^2

// How is this relevant to this algorithm ?
// Suppose the distance between two nodes u and v is d, then we can represent d as sum of power of 2.Now if we 
// make jumps only to these levels then v can be reached from u in at most log(d) steps.

// Time Complexity -
// Preprocessing - O(nlogn)
// 		The 2-D DP array stores the 2^i th ancestor of each node.Now the value of i in the worst case can be 
// 		log(N) as the distance between any 2 nodes can be maximum N.So maximum number of ancestors stored for 
// 		any node can be logN.Filling up the DP array requires one DFS for assigning immediate parent followed 
// 		by filling up of DP array of size NlogN. 
// Query -	O(logn)
// 		The distance between node and LCA can be maximum 'n'.As the 2^i th ancestor is already computed reaching 
// 		the LCA would require at most logn jumps.
// Space Complexity - O(nlogn)
// 		2D DP array is of size nlogn as any node can have maximum logn ancestors.

// Comparison with other methods of finding LCA :
// 1) Naive approach :
//  	No Preprocessing required
//  	Query - O(n) as the tree needs to be traversed
// 	Space Complexity - O(n)

// 2) RMQ approach : 
// 	Preprocessing -> O(n)
// 		Euler Tour : DFS is done for creating the baseArray and assigning the depth to each node.
// 			     Complexity of DFS = O(V+E)
// 			     For a tree having n nodes E = n-1
// 			     So complexity of this step = O(n)
// 		Building the segment tree : Each time a node is visited during the euler tour it is pushed into the baseArray.
// 			     Corresponding to each edge of the tree 2 nodes are pushed into the baseArray as each edge is 
// 			     traversed 2 times, once while going into the subtree and once while coming out and durign each
// 			     traversal one node is pushed into the baseArray.The root is pushed into the baseArray at the start
// 			     of the tour. So the total size of baseArray = 2*(n-1) + 1 = 2n-1
// 			     We know for a baseArray of size n the complexity of building a segment tree is O(n).
// 			     Complexity of this step = O(n)
// 	Query -> Each query is simply range minimum query in the segment tree of size O(n).So time complexity per query
// 	    	is O(log n).

// Now if we compare the Binary Lifting approach with these 2 approaches, we see that the naive approach and RMQ approach
// have the same space complexity which is less than Binary Lifting approach.

// If there is a single query naive approach can be used as it requires no preprocessing and answers query in 
// O(n), contrary to other approaches which require O(nlogn) time for preprocessing and O(logn) for query.

// If there are multiple queries then Binary Lifting or RMQ must be used as they require O(logn) time answering 
// per query.
