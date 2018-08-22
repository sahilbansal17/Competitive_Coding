//Name:Anuj Goyal
//Email:anujg935@gmail.com


//This program gives the binary tree from
	//PreOrder and Inorder traversal
	//PostOrder and Inorder traversal
#include<iostream>

using namespace std;

//BinaryTreeNode class is to implement tree
template<typename T>
class BinaryTreeNode{
	public:
		//data of the node
		T data;
		//each node contains the adress of 2 nodes i.e left and right
		BinaryTreeNode *left;
		BinaryTreeNode *right;
		
		//contructor to make the node and initialize their values
	    BinaryTreeNode(T data){
	    	this->data = data;
	    	left =NULL;
	    	right =NULL;
		}
		//Destructor that deletes the tree whenever needed
		~BinaryTreeNode(){
			delete left;
			delete right;
		}
}; 

//This function is the helper function to the funtion getTreeFromPreorderAndInorder()
//This function the root of binary tree

BinaryTreeNode<int>* binaryTreePreIn(int *preorder,int preS,int preE,int *inorder,int inS,int inE){
	//Base case for recursion when starting index of inorder array is greater than ending index
	//as the size of bot inorder and preeorder array are same
	if(inS>inE){
		return NULL;
	}
	//as preeorder first prints the root data than 
	//at the starting index of preorder Array there is root
	int rootData = preorder[preS];
	
	//Building a binary tree with rootData as the root node
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	int rootIndex;
	
	//searching for the rootData to find the index of root data in inorder array
	//this helps us in finding the the ending index of left tree 
	for(int i=inS;i<=inE;i++){
		if(rootData == inorder[i]){
	    	rootIndex =i;
	    	break;
	    }
	}
	
	//For calling recursion we need similar small problem 
	//for that we need the value of following 8 variables that are 
	//starting and ending indexes for smaller problem 
	
	//For PreOrder array :- |Root||Left||Right|
	//For InOrder array :-  |Left||Root||Right|
	//these above 2 lines of information helps you in findinng the
	//indexes of left and right subtree   
	int lPreS = preS+1;
	int lInS = inS;
	int lInE = rootIndex-1;
	int lPreE = lInE+lPreS-lInS;
	  
	int rPreS = lPreE+1;
	int rPreE = preE;
	int rInS = rootIndex+1;
	int rInE = inE;
	
	//calling recursion on left and right subtree with their indexes
	//and connecting the result from recursion to the left and right 
	//of the root respectively
	root->left = binaryTreePreIn(preorder,lPreS,lPreE,inorder,lInS,lInE);
	root->right= binaryTreePreIn(preorder,rPreS,rPreE,inorder,rInS,rInE);
	
	//returning the rootnode of the tree
	return root;
}

//Function that takes preorder and inorder traversal array,and returns the root of the the tree
BinaryTreeNode<int>* getTreeFromPreorderAndInorder(int *preorder, int *inorder, int size) {
	//calling and returnig of the helper function
	return binaryTreePreIn(preorder,0,size-1,inorder,0,size-1);
}

//This function is the helper function to the funtion getTreeFromPostOrderAndInorder()
//This function the root of binary tree
BinaryTreeNode<int>* binaryTreePostIn(int *postorder,int postS,int postE,int *inorder,int inS,int inE){
	//Base case for recursion when starting index of inorder array is greater than ending index
	//as the size of bot inorder and preeorder array are same
	if(inS>inE){
		return NULL;
  	}
  	
  	//for this case we need to find out the rootIndex 
  	//because in postorder as well as inorder none of the array contains root ia first element
  	//as in the case of preorder
	int rootIndex;
	//we know that in postOrder Traversal the root is printed in the end
	//therfore,the root data can be found in the ending index of postorder array
	//for finding the index of rootData in inorder array we are iterating over inorder array
	for(int i=inS;i<=inE;i++){
		if(postorder[postE] == inorder[i]){
    		rootIndex =i;
      		break;
    	}
  	}
  	//taking root data in rootData variable
  	//and making a tree with rootData 
	int rootData = inorder[rootIndex];
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
  	
  	//For calling recursion we need similar small problem 
	//for that we need the value of following 8 variables that are 
	//starting and ending indexes for smaller problem 
	
	//For PostOrder array :- |Left||Right||Root|
	//For InOrder array :-  |Left||Root||Right|
	//these above 2 lines of information helps you in findinng the
	//indexes of left and right subtree
  	int lPostS = postS;
  	int lInS = inS;
  	int lInE = rootIndex-1;
  	int lPostE = lInE+lPostS-lInS;
  	int rPostS = lPostE+1;
  	int rInS = rootIndex+1;
  	int rInE = inE;
  	int rPostE = rInE-rInS+rPostS;
  	
  	//calling recursion on left and right subtree with their indexes
	//and connecting the result from recursion to the left and right 
	//of the root respectively
  	root->left = binaryTreePostIn(postorder,lPostS,lPostE,inorder,lInS,lInE);
  	root->right= binaryTreePostIn(postorder,rPostS,rPostE,inorder,rInS,rInE);
  	
  	//returning the rootnode of the tree
	return root;
}

//Function that takes postorder and inorder traversal array,and returns the root of the the tree
BinaryTreeNode<int>* getTreeFromPostOrderAndInorder(int *postorder, int *inorder, int size) {
	//calling and returnig of the helper function
	return binaryTreePostIn(postorder,0,size-1,inorder,0,size-1);
}

//this print function takes the root of tre and print the the tree 
void print(BinaryTreeNode<int>* root){
	//base case of recursion
	if(root==NULL){
		return;
	}
	//printing root data
	cout<<root->data<<":";
	//printing the left data of root node
	if(root->left !=NULL){
		cout<<"L "<<root->left->data<<",";
	}
	//printing the left data of root node
	if(root->right !=NULL){
		cout<<"R "<<root->right->data;
	}
	cout<<endl;
	//calling recursion on left and right part of tree
	print(root->left);
	print(root->right);
}
//main function that drives the program

int main()
{
	//for demo we take the preorder and inorder of the following bnary Tree
		//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
	//
	//                       1
	//                     /   \
	//                    2     3
	//                   / \   / \
	//                  4  5   6  7
	//                        / \
	//                       8   9
	//
	
	//preorder array for this tree is :- 1,2,4,5,3,6,8,9,7
	//inorder array for this tree is :- 4,2,5,1,8,6,9,3,7
	//postorder array for this tree is :- 4,5,2,8,9,6,7,3,1
	
	int preorder[] ={1,2,4,5,3,6,8,9,7};
	int inorder[] ={4,2,5,1,8,6,9,3,7};
	int postorder[]={4,5,2,8,9,6,7,3,1};
	
	//calling the 2 functions and siving thier roots in root1 and root2
	BinaryTreeNode<int>* root1 = getTreeFromPreorderAndInorder(preorder,inorder,9);
	BinaryTreeNode<int>* root2 = getTreeFromPostOrderAndInorder(postorder,inorder,9);
	
	cout<<"Tree we get from getTreeFromPreorderAndInorder function"<<endl;
	print(root1);
	
	cout<<"Tree we get from getTreeFromPostOrderAndInorder function"<<endl;
	print(root2);
}
