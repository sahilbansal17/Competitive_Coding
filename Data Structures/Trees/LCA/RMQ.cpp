// This program finds the LCA of two nodes in a rooted tree using Euler Tour
// and Range Minimum Query

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const int L=1e5+7;

// baseArray is the input array
// seg stores the values stored in nodes of segment trees
// pos_in_base stores the first occurrence of node in baseArray
// level stores the depth of node with respect to root
int baseArray[L], seg[4*L], pos_in_base[L], level[L];
int size_of_base, start_time = 1, number_of_nodes;
std::vector<int> v[L];
// DFS function for creating the baseArray
void eulerTour(int vertex, int parent)
{
	// first occurrence of node in Euler Tour
	pos_in_base[vertex] = start_time;
	baseArray[start_time++] = vertex;
	// assigning level of vertex wrt root
	level[vertex] = level[parent] + 1;
	for(auto &x : v[vertex])
	{
		if(x != parent)
		{
			eulerTour(x, vertex);
		}
		baseArray[start_time++] = vertex;
	}
	return;
}
void build(int start = 1, int end = size_of_base, int index = 1)
{
	// Leaf Node
	if( start == end )
	{
		seg[index] = baseArray[start];
		return;
	}
	int mid = (start + end)/2;

	// Recursive calls for children
	build(start, mid, 2*index);
	build(mid+1, end, 2*index + 1);

	// current segtree node stores the node with minimum level in current range
	if(level[ seg[2*index] ] < level[ seg[2*index + 1] ])
	{
		seg[index] = seg[2*index];
	}
	else
	{
		seg[index] = seg[2*index + 1];
	}
	return;
}

// [l,r] represent the query range
int query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	// current range is outside the query range so return node initialised with 
	// very large level 
	if( start > r || end < l )return number_of_nodes + 1;

	// current range lies completely inside the query range so return value stored
	// in the segtree node
	if(start >= l && end <= r)
	{
		return seg[index];
	}

	int mid = (start + end)/2, query_left, query_right;

	// query both children to find node with minimum level in the subtree
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	
	if(level[ query_left ] < level[ query_right ])
	{
		return query_left;
	}
	else
	{
		return query_right;
	}
}
int main()
{
	int queries, v1, v2, LCA;
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
	// Assuming 1 is the root of the tree
	eulerTour(1,-1);
	// dummy node, not part of original tree
	level[number_of_nodes + 1] = INT_MAX; 
	size_of_base = start_time - 1;
	build();

	cout << "Enter number of queries->";
	cin >> queries;

	while( queries-- )
	{
		cout << "Enter vertices -> " ;
		cin >> v1 >> v2;
		// node which occurs 1st in the baseArray must be v1
		// if it is not so then swap v1, v2	
		if(pos_in_base[v1] > pos_in_base[v2])
		{
			swap(v1, v2);
		}
		// pos_in_base stores the first occurrence of node in baseArray
		LCA = query(pos_in_base[v1], pos_in_base[v2]);
		cout << "LCA of "<< v1 <<" and "<< v2 <<" is "<< LCA <<endl;
	}
	return 0;
}
// Euler tour is the path along the tree that begins at the root and ends at the root, traversing 
// each edge exactly twice — once to enter the subtree at the other endpoint and once to leave it. 
// Whenever we reach a node, it is pushed into the baseArray. 
// If the path traced by the euler tour is carefully observed then we'll see that it stores the path
// between any two nodes of the tree and the LCA of the two nodes is the node with the minimum depth
// in the path.
// Consider this tree ->               1
// 		     		   / 	   \
// 			    	  2	    3
// 			       /    \
// 			      4	     5
// 		baseArray : 1 -> 2 -> 4 -> 2 -> 5 -> 2 -> 1 -> 3 -> 1
// If we pick any two nodes of the tree we'll find a path between the nodes in the baseArray.
// eg - 5 and 3 : 5 -> 2 -> 1 -> 3

// Now using this observation we can find the LCA easily. Perform an euler tour and build the baseArray 
// and also assign the depth of each node wrt the root. Now for finding the LCA simply query for the minimum 
// depth between the first occurrence(Any occurrence would give the correct answer) of the nodes in the baseArray.
// This type of query can be easily answered using the segment tree.

// Time Complexity:
// Preprocessing -> 
// Euler Tour : DFS is done for creating the baseArray and assigning the depth to each node.
// 		Complexity of DFS = O(V+E)
// 		For a tree having n nodes E = n-1
// 		So complexity of this step = O(n)
// Building the segment tree : Each time a node is visited during the euler tour it is pushed into the baseArray.
// 		Corresponding to each edge of the tree 2 nodes are pushed into the baseArray as each edge is 
// 		traversed 2 times, once while going into the subtree and once while coming out and durign each
// 		traversal one node is pushed into the baseArray.The root is pushed into the baseArray at the start
// 		of the tour. So the total size of baseArray = 2*(n-1) + 1 = 2n-1
// 		We know for O(n) nodes the complexity of building a segment tree is O(n).
// 		Complexity of this step = O(n)
// Query -> Each query is simply range minimum query in the segment tree of size O(n).So time complexity per query
// 	    is O(log n).

// Space Complexity : O(n) space is required for segment tree as well as the input tree.
// 		      So overall space complexity is O(n).

// Comparison with other methods of finding LCA :
// 1) Naive approach :
//  	No Preprocessing required
//  	Query - O(n) as the tree needs to be traversed
// 	Space Complexity - O(n)

// 2) Sparse matrix DP approach :
// 	Preprocessing - O(nlogn)
// 			The 2-D DP array stores the 2^i th parent of each node.Now the value of i in 
// 			the worst case can be logN.So maximum number of ancestors stored for any node 
// 			can be logN.Filling up the DP array requires one DFS for assigning immediate parent 
// 			followed by filling up of DP array of size NlogN. 
// 	Query -	O(logn)
// 		The distance between node and LCA can be maximum 'n'.As the 2^i th parent is already computed
// 		reaching the LCA would require at most logn jumps.
// 	Space Complexity - O(nlogn)
// 			   2D DP array is of size nlogn as any node can have maximum logn parents.

// Now if we compare the RMQ approach with these 2 approaches, we see that the naive approach and RMQ approach
// have the same space complexity which is less than Sparse DP approach.

// If there is a single query naive approach can be used as it requires no preprocessing and answers query in 
// O(n), contrary to other approaches which require O(nlogn) time for preprocessing and O(logn) for query.

// If there are multiple queries then sparse DP approach or RMQ must be used as they require O(logn) time answering 
// per query. The time and space complexity of sparse DP approach is greater than the RMQ approach. So RMQ can be
// preffered.
