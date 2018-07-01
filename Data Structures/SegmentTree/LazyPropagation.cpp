// This program finds the LCM of numbers in given range of array and also handles range updates
// of multiplying a range by a given number

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int L=1e5+7;
// baseArray is the input array
// seg stores the values stored in nodes of segment trees
// lazy stores the value which needs to be multiplied to range represented by node in the segment tree
// and is initialised with 1
int size_of_base;
std::vector<int> baseArray(L);
std::vector<int> seg(4*L);
std::vector<int> lazy(4*L, 1);

int findLCM(int a, int b)
{
	int product = a * b;
	int HCF = __gcd(a, b);

	// Using the formula LCM * HCF = Product of numbers
	int LCM = product / HCF;
	return LCM;
}

// recursive function to build the segment tree
// start and end represent the current range in the baseArray
// index represents the current index of the segment tree 
void build(int start = 1, int end = size_of_base, int index = 1)
{
	// Leaf Node
	if( start == end )
	{
		// As leaf node stores single value and LCM of single number is
		// the number itself
		seg[index] = baseArray[start];
		return;
	}
	int mid = (start + end)/2;

	// Recursive calls for children
	build(start, mid, 2*index);
	build(mid+1, end, 2*index + 1);

	// current node stores the LCM of values in the subtree
	seg[index] = findLCM(seg[2*index], seg[2*index + 1]);
	return;
}

void lazyUpdate(int start, int end, int index)
{
	// if current node has a pending update then update value of current node
	// and propagate the update value to children
	if(lazy[index] != 1)
	{
		// The current node stores the LCM of range [start, end] in the baseArray. Now if 
		// lazy[index] is multiplied to each element in this range, the highest power of 
		// all prime factors of lazy[index] increases by 1 so new_LCM = original_LCM * lazy[index]
		seg[index] *= lazy[index];

		// propagating value to children if current node is not a leaf node
		// if start == end then current node is a leaf node and thus has no children
		if(start != end)
		{
			lazy[2*index] *= lazy[index];
			lazy[(2*index) + 1] *= lazy[index];
		}
		lazy[index] = 1;
	}
	return;
}

// function for range update in segment tree
// [l, r] corresponds to the range to which value is to be added
void updateRange(int l, int r, int value, int start = 1, int end = size_of_base, int index = 1)
{
	// check if update in this node is pending
	lazyUpdate(start, end, index);

	// current range doesn't intersect with [l, r]
	if(r < start || l > end || start > end )return;
	
	// current range lies within [l, r]
	if( l <= start && r >= end )
	{
		seg[index] *= value;

		// if start != end then current node is not a leaf node and has children
		// So propagate update value to children
		if(start != end)
		{
			lazy[2*index] *= value;
			lazy[2*index + 1] *= value;
		}
		return;
	}

	int mid = (start + end)/2;

	// Recursive calls for children
	updateRange(l, r, value, start, mid, 2*index );
	updateRange(l, r, value, mid+1, end, 2*index + 1);

	// current node stores the LCM of values in the subtree
	seg[index] = findLCM(seg[2*index], seg[2*index + 1]) ;
	return;
}

// [l,r] represent the query range
int query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	// check if update in this node is pending
	lazyUpdate(start, end, index);

	// current range is outside the query range so return 1
	if( start > r || end < l || start > end)
	{
		return 1;
	}

	// current range lies completely inside the query range so return value stored
	// in the node
	if(start >= l && end <= r)
	{
		return seg[index];
	}

	int mid = (start + end)/2, query_left, query_right;

	// query both children to find LCM of values in the subtree
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);

	return findLCM(query_left, query_right);
}
int main()
{
	int operations, idx, value, l, r;
	char type;

	cout << "Enter size of array = ";
	cin >> size_of_base;
	cout << "Enter numbers ";
	for (int i = 1; i <= size_of_base; ++i)
	{
		cin >> baseArray[i];
	}
	// building the segment tree
	build();

	cout << "Enter number of operations = ";
	cin >> operations;

	while( operations-- )
	{
		cout << "Enter operation: Q for query, U for update" << endl;
		cin >> type;

		if( type == 'Q' )
		{
			cout << "Enter query range" << endl;
			cin >> l >> r;
			cout << query(l, r) << endl;
		}
		else if( type == 'U' )
		{
			cout << "Enter updateRange and value (1 based indexing) = ";
			cin >> l >> r >> value;
			updateRange(l, r, value);
		}
	}
	return 0;
}

// Refer to SegmentTree.cpp in the same folder for explanation about basics of Segment Tree and
// related Time and Space Complexities.

// Why do we need lazy propagation?
// For range update a naive approach can be updating each value in the given range one by one in 
// the baseArray and then rebuilding the segment tree. Now updating each value would take O(n) time 
// and building segment tree would also take O(n). So overall complexity of update would become O(n).
// This is where lazy propagation comes to our rescue.

// We keep a lazy array which stores the value which must be multiplied to current range. Whenever we reach 
// a node during query or update, we first update its value if the lazy value is not 1 and 
// propagate this value to its children as the whole subtree needs to be updated. 

// Now during update operation if we come across a node which lies completely inside the update interval,
// we update its value, propagate the value to its children and return. This way we avoid updating 
// the whole subtree.

// The proof of time complexity of update is similar to the proof of complexity of query function.
// We first prove that at each level at most two nodes are expanded.
// This can be proved by contradiction.Consider a case that 3 nodes must be expanded(namely c1,c2,c3)
// 		   		    p1       p2
// 				  /    \   /    \
// 				c1     c2  c3   c4 		
// This means range [l,r] lies from c1 to c3.But if it is so then we would have returned from p1 as 
// it lies completely inside the update interval because according to the algorithm if we come across
// a node which lies completely inside the update range we update its value, propagate the value to its
// children and return.So p1 must not be expanded. This is a contradiction.

// So at each level at most 2 nodes will be expanded.So total no of visited nodes = 2*height of tree
// Time complexity of update = O(logn)	as height of tree = O(logn)