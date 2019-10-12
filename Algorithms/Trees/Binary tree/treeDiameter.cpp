//Name : Aditya Neel
//email : adityaneil0236@gmail.com

//program to calculate the diameter of a binary tree

#include<bits/stdc++.h>
using namespace std;

typedef struct treeNode{
	int data;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

/* desc : creates a new tree node 
   input : integer data
*/
treeNode* newNode(int data){
	treeNode* t = new treeNode;
	t->data = data;
	t->left = NULL;
	t->right = NULL;
	return t;
}

/* desc : calculates the diameter of the tree
   input : root of the binary tree
*/
int treeDiameter(treeNode* root,int &dia){
	if(!root)
		return 0;
	if(!root->left && !root->right)
		return 1;
	int lh = treeDiameter(root->left,dia);
	int rh = treeDiameter(root->right,dia);
	if(root->left && root->right){
		dia = lh + rh + 1;
		return (max(lh,rh) + 1);	
	}
	if(!root->left)
		return rh + 1;
	return lh + 1;
}

/*
		  4
		/   \
		10  15
	   /  \   \
	   2  20   16
	    \
	     8	
*/
int main(){
    int result,dia = 0;
	treeNode* root = newNode(4);
	root->left = newNode(10);
	root->right = newNode(15);
	root->left->right = newNode(20);
	root->right->right = newNode(16);
	root->left->left = newNode(2);
	root->left->left->right = newNode(8);
	result = treeDiameter(root,dia);
    cout<<"Diameter = "<<result;
}