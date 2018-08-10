//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is that given a binary tree we need to 
//find the BST with maximum height in the given binary tree
#include<climits>
#include<iostream>
#include<queue>
using namespace std;

//Binary tree node class for binary tree
template<typename T>
class BinaryTreeNode {
    public : 
    	//data of node
        T data;
	    BinaryTreeNode<T> *left;
	    BinaryTreeNode<T> *right;
		//constructor that initializes the object during reation
	    BinaryTreeNode(T data) {
	        this -> data = data;
	        left = NULL;
	        right = NULL;
	    }
};

//takes the input level wise for binary tree and returns the root of the tree
BinaryTreeNode<int>* takeInputLevelWise(){
	cout<<"Enter root Data :";
	int rootData;
	cin>>rootData;
	if(rootData ==-1){
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty()){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<<"Enter left Child of "<<front->data<<endl;
		int leftChildData;
		cin>>leftChildData;
		if(leftChildData!=-1){
			BinaryTreeNode<int>*child= new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		
		cout<<"Enter right Child of "<<front->data<<endl;
		int rightChildData;
		cin>>rightChildData;
		if(rightChildData!=-1){
			BinaryTreeNode<int>*child= new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}

//subBST class that is used to find various parameters
//to check for the BST in subtree of binary tree
class subBST{
  public:
  int min;
  int max;
  int maxheight;
  bool isBST;
};

//this validate funtion has all the data from the left subtree ,right subtree and of the root node of given tree
//so that function is just to make decision on larges BST according to data provided
subBST validate(subBST leftans,subBST rightans,BinaryTreeNode<int> * root)
{
	//if the left and right both the subtrees are BST
  	if(leftans.isBST==true && rightans.isBST==true)
  	{
  		//further if the root node value is greater than max of left subtree and
		//and min of right subtree than the whole tree is BSR 
    	if(root->data>leftans.max && root->data<rightans.min)
    	{
    		//so creating a object result of class subBST
      		subBST result;
      		//minimum and maximum values of the tree is the min and max of all the 
      		// 3 root node left subtree and right subtree
      		result.min=min(root->data,min(leftans.min,rightans.min));
      		result.max=max(root->data,max(leftans.max,rightans.max));
      		//its definately a BST
      		result.isBST=true;
      		//height of resultant BST
      		result.maxheight=1+max(leftans.maxheight,rightans.maxheight);
      		return result;
    	}
    	//if above is not the case than the subtree is not BST
    	//and min and max are also -1
    	else
    	{
      		subBST result;
      		result.isBST=false;
      		result.min=-1;
      		result.max=-1;
      		result.maxheight=max(leftans.maxheight,rightans.maxheight);
      		return result;
   		}
  	}
  	else{
    	if(leftans.maxheight>rightans.maxheight)
    	{
      		leftans.isBST=false;  //possible that it may be true and right be false
      		return leftans;
    	}
    	else{
      		rightans.isBST=false;  //possible that it may be true and left be false
      		return rightans;
    	}
  	}
}

//its a helper function to the largestBSTsubtree() which you can find below
subBST largestBSTsubtree(BinaryTreeNode<int> *root)
{
	//base case for recursive function
	//if the root  is NULl then ther is no tree 
	//if thats the case than its also a BST an its height is zero
	if(root==NULL)
  	{
    	subBST result;
    	result.min=INT_MAX;
    	result.max=INT_MIN;
    	result.maxheight=0;
    	result.isBST=true;
    	return result;
  	}
  	
  	//calling recursion on left and right subtree
  	//and saving their values in leftans and rightans respectively
  	subBST leftans=largestBSTsubtree(root->left);
  	subBST rightans=largestBSTsubtree(root->right);
  	
  	//calling and returning a validate function that takes the root of the tree
  	//and the answers from left and right subtree
  	return validate(leftans,rightans,root);
}

//largestBSTSubtree () function returns the length of largest BST present in the 
//given binary tree
int largestBSTSubtree(BinaryTreeNode<int> *root)
{
	//this function calls a helper function that returns subBST data type
	//and returning the the height from the result object
	subBST result=largestBSTsubtree(root);
	return result.maxheight;
}

//main function that drives the program
int main()
{
	BinaryTreeNode<int>* root = takeInputLevelWise();
	//                   5
	//                 /  \
	//                10   6
	//               / \   
	//              2  3 
	//                  \
	//                   9
	//the inputs for above tree is as follows:
	//5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
	
	cout<<"Maximum Height BST in given binary tree is : "<<largestBSTSubtree(root)<<endl;
}

