/*

Given a balanced binary search tree (take a sample tree in your code) and a number x, 
your task is to determine if there exists a pair of nodes, such that their sum is equal to x.
Every node contains a value, left ptr and right ptr.

The following tasks need to be done for an entire score:

1. Return the larger of the two numbers if there exists a pair, else -1 in time O(n).
2. Space taken should be less than O(n).
3. Explanations for all methods and time/space complexities.

*/
#include <iostream>
#include <stack>
using namespace std;
struct node
{
	int val;
	node* left;
	node *right;
};
// initialising node
node *new_node(int val)
{
	node *cur =new node();
	cur->val = val;
	cur->left = NULL;
	cur->right = NULL;
}
// Function for insertion of node in the tree
node *insert(node * root,int val)
{
	if(root==NULL)
	{
		root = new_node(val);
		return root;
	}
	if(val < root->val)
	{
		root->left = insert(root->left, val);
	}
	else
	{
		root->right = insert(root->right,val);
	}
	return root;
}
// stack to store the nodes encountered in the inorder and reverse inorder traversals
// It is used in place of the recursion stack as the algorithm is iterative and not recursive
stack <node*> fwd, bwd;

// v1 and v2 correspond to the array[l] and array[r] in array based implementation
int v1, v2;

// function for finding inorder successor
node* findSuccessor(node * root)
{
	// traverse the left subtree if it exists
	while(root != NULL)
	{
		fwd.push(root);
		root = root->left;
	}
	// Empty stack implies traversal of whole tree is already done
	if(fwd.empty())
	{
		return NULL;
	}
	// For any node on the top the stack we can say that it's left subtree has already been traversed. 
	// Left nodes are pushed into the stack and if current node is on top of the stack it means its left 
	// child and its children have already been popped from stack which means they have already been traversed.
	// In case of inorder traversal we move from left->root->right. Since the left subtree of current node has 
	// already been traversed we assign v1 = current->val and current->right to l so that traversal in next step 
	// starts from the current node's right subtree. 
	node *cur = fwd.top();
	fwd.pop();
	v1 = cur->val;
	return cur->right;
}
// function for finding inorder predecessor
node* findPredecessor(node * root)
{
	// traverse the right subtree if it exists
	while(root != NULL)
	{
		bwd.push(root);
		root = root->right;
	}
	// Empty stack implies traversal of whole tree is already done
	if(bwd.empty())
	{
		return NULL;
	}
	// For any node on the top the stack we can say that it's right subtree has already been traversed. 
	// Right nodes are pushed into the stack and if current node is on top of the stack it means its right 
	// child and its children have already been popped from stack which means they have already been traversed.
	// In case of reverse inorder traversal we move from right->root->left. Since the right subtree of current 
	// node has already been traversed we assign v1 = current->val and current->left to r so that traversal in 
	// next step starts from the current node's left subtree. 
	node *cur = bwd.top();
	bwd.pop();
	v2 = cur->val;
	return cur->left;
}
int find(node* root, int val)
{
	// The left and right pointers in this case are slightly different from the array based implementation
	// They point to the node from where traversal starts in the next step contrary to the array based 
	// implementation where the pointers point to the indices of both numbers whose sum is being considered.
	// We keep separate variables (v1 and v2) to store the numbers whose sum is being considered. 
	node *l = findSuccessor(root);
	node *r = findPredecessor(root);
	// loop runs till v1 < v2
	// In each step we either increase the value of v1 or decrease the value of v2 till we find the required
	// sum or v1 becomes greater than v2
	while(v1 < v2)
	{
		// if current sum = val return maximum of both values
		if(v1 + v2 == val)
		{
			return max(v1, v2);
		}
		// if current sum is less than the required sum then increase the value of v1 i.e. find the smallest 
		// number in the tree greater than v1 . This means find inorder successor of v1.
		// This is similar to increasing the left pointer by 1 in array based implementation. 
		else if(v1 + v2 < val)
		{
			l = findSuccessor(l);
		}
		// if current sum is greater than the required sum then decrease the value of v2 i.e. find the largest 
		// number in the tree smaller than v2 . This means find inorder predecessor or reverse inorder successor 
		// of v1.
		// This is similar to decreasing the right pointer by 1 in array based implementation. 
		else
		{
			r = findPredecessor(r);
		}
	}
	return -1;
}
int main()
{
	int num;
	// Sample tree
	//	 	10
	//	   /	      \
	//	 5	       50
	//     /   \	      /  \
	//    3     6	     40   51
	node *root = NULL;
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 50);
	root = insert(root, 3);
	root = insert(root, 6);
	root = insert(root, 40);
	root = insert(root, 51);
	cout << "Enter sum = ";
	cin >> num;
	cout << find(root, num)<<endl;
	return 0;
}
// Time Complexity : O(n)
// 		     Inorder and Reverse Inorder traversal is done, the complexity of these traversals is 
// 		     O(n) for a tree having n nodes. So time complexity of the algorithm is O(n).

// Space Complexity : O(log n)
// 		      The stack stores all the ancestors of the current node. So the maximum size of stack at
// 		      any point of time can be O(h) as maximum number of ancestors of any node can be maximum
// 		      h. And since this is a balanced BST h= O(logN).
// 		      So space complexity is O(logn)
