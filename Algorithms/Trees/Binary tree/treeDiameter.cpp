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

/* desc : insert a node in the tree
   input : root and integer data
  */
treeNode* insert(treeNode* root,int data){
	if(!root){
		return newNode(data);
	}
	if(data < root->data){
		root->left = insert(root->left,data);
	}
	if(data > root->data){
		root->right = insert(root->right,data);
	}
	return root;
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

int main(){
	treeNode* root = NULL;
    int n,data,result,dia = 0;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>data;
		root = insert(root,data);
	}
	result = treeDiameter(root,dia);
    cout<<"Diameter = "<<result;
}