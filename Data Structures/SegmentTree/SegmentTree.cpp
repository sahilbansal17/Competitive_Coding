// This program finds the minimum value in given range (RMQ) in an array 

#include <iostream>
#include <limits.h>
using namespace std;

const int L=1e5+7;
// baseArray is the input array
// seg stores the values stored in nodes of segment trees
int baseArray[L], seg[4*L],size_of_base;

// recursive function to build the segment tree
// start and end represent the current range in the baseArray
// index represents the current index of the segment tree 
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

	// current node stores the minimum value in its subtree
	seg[index] = min( seg[ 2*index ] , seg[ 2*index + 1] );
	return;
}

// function for point update in segment tree
// updateindex corresponds to the index which is to be updated
void update(int updateindex, int start = 1, int end = size_of_base, int index = 1)
{
	// index doesn't lie in current range so return
	if(updateindex < start || updateindex > end)return;

	// current node corresponds to updateindex in baseArray
	if( start == end && updateindex == start )
	{
		seg[index] = baseArray[start];
		return;
	}

	int mid = (start + end)/2;

	// Recursive calls for children
	update(updateindex, start, mid, 2*index );
	update(updateindex, mid+1, end, 2*index + 1);

	// current node stores the minimum value in its subtree
	seg[index] = min( seg[ 2*index ] , seg[ 2*index + 1] );
	return;
}

// [l,r] represent the query range
int query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	// current range is outside the query range so return very large value
	if( start > r || end < l )return INT_MAX;

	// current range lies completely inside the query range so return value stored
	// in the node
	if(start >= l && end <= r)
	{
		return seg[index];
	}

	int mid = (start + end)/2, query_left, query_right;

	// query both children to find minimum value in the subtree
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);

	return min(query_left, query_right);
}
int main()
{
	int operations, idx, value, l, r;
	char type;

	cout<<"Enter size of array=";
	cin>>size_of_base;
	cout<<"Enter numbers ";
	for (int i = 1; i <= size_of_base; ++i)
	{
		cin>>baseArray[i];
	}
	// building the segment tree
	build();

	cout<<"Enter number of operations=";
	cin>>operations;

	while( operations-- )
	{
		cout<<"Enter type of operation: Q for query , U for update"<<endl;
		cin>>type;

		if( type == 'Q' )
		{
			cout<<"Enter query range"<<endl;
			cin >> l >> r;
			cout<<query(l, r)<<endl;
		}
		else if( type == 'U' )
		{
			cout<<"Enter index and value (1 based indexing)=";
			cin >> idx >> value;
			baseArray[idx] = value;
			update(idx);
		}
	}
	return 0;
}
// Before mentioning the time and space complexity let's see why the size of segment tree is 4 times 
// the size of baseArray.
// A segment tree is a full binary tree in which each node must have 2 children. The leaf nodes are 
// occupied by the elements in the baseArray. So number of leaf nodes = n.Since it is a full binary 
// tree at each level the number of nodes decreases by half. So the height of tree = ceil[ log(n) ].
// So the total number of nodes in the segment tree = 2^0 + 2^1 + ....... + 2^(ceil[ log(n) ])
// number of nodes = 2^(ceil[ log(n) ] + 1) -1 = 2*2^(ceil[ log(n)])   (neglecting 1 as n can be large)
// Now consider 2 cases :
// i)  n = 2^m  => ceil[ log(n) ] = m 
//	   So number of nodes in this case = 2*2^m = 2*n 
// ii) n = (2^m+1) => ceil[ log(n) ] = log(2^(m+1)) = m+1
//     So number of nodes in this case = 2*2^(m+1) = 4*2^m = 4n (approx)
// So in the worst case the size of the segment tree can be 4 times the size of the baseArray.

// Space Complexity = O(n)

// Time complexity:
// build - Each node in the segment tree must be visited atleast once and  we have already proved number 
//	   of nodes can be 4n .So complexity of build function is O(n).

// update - At each visited node we either move to it's left subtree or right subtree as the index to 
//	    be updated can only be in one of the two subtrees. This means that we visit exactly one node
//	    at each level of the tree and as height of the tree is O(logN) time complexity of update is O(logN).

// query - We first prove that at each level at most two nodes are expanded.
//	   We'll prove this by contradiction.Consider a case that 3 nodes must be expanded(namely c1,c2,c3)
// 		   		    p1       p2
//				  /    \   /    \
//				c1     c2  c3   c4 		
// 	   This means range [l,r] lies from c1 to c3.But if it is so then node p1 wouldn't have been expanded as
//         it already contains the minimum value in the subtree of c1 and c2.This is a contradiction.So at 
//	   each level at most 2 nodes will be expanded.So total no of visited nodes = 2*height of tree
//         Time complexity = O(logN)	as height of tree = O(logN)
