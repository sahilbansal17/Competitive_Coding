//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to find the diameter of the binary tree
//diameter of binary tree is the maximum distance b/w any two nodes of binary tree
#include<iostream>
#include<queue>
using namespace std;

//BinaryTreeNode class of binary tree
template<typename T>
class BinaryTreeNode{
	public:
		T data;
		BinaryTreeNode *left;
		BinaryTreeNode *right;
		//constructor of class to initialize it
	    BinaryTreeNode(T data){
	    	this->data = data;
	    	left =NULL;
	    	right =NULL;
		}
		//destructor to delete the object
		~BinaryTreeNode(){
			delete left;
			delete right;
		}
}; 

//height() function is a function that returns the height of the the tree
//this height function helps in other function to find the diameter
int height(BinaryTreeNode<int>* root){
	//base case for recursion
	if(root==NULL){
		return 0;
	}
	return 1+ max(height(root->left) ,height(root->right));
}

//This is the basic approach to find thhe diameter of the the given binary tree
int diameter(BinaryTreeNode<int>* root){
	//base case of recursion
	if(root==NULL){
		return 0;
	}
	//there are 3 cases of finding the diameter 
	//it can be the sum of the heights of right and left subtree
	int option1 = height(root->left) + height(root->right);
	//recursive call on left and right subtree
	int option2 = diameter(root->left);
	int option3 = diameter(root->right);
	
	//returning the maximum value which we get from the 3 options
	return max(option1,max(option2,option3));
}

//This is the second approach of finding the diameter it's efficient thn previous approach
//in the previous approach we are calling a function again and again and finding height and diameter
//both diameter and height can be done in the single way

//we are using inbuilt pair class both of int type for height and diameter   
pair<int, int> heightDiameter(BinaryTreeNode<int>* root) {
	//base case for recursion when root==NULL
	if (root == NULL) {
		//making pair class object p
		pair<int, int> p;
		//height and diameter is 0 when root= null
		p.first = 0;
		p.second = 0;
		//returning p  
		return p;
	}
	
	//calling recursion on both sides of binary tree i.e left and right side
	//saving the output of boh halfs in leftAns and rightAns
	pair<int, int> leftAns = heightDiameter(root->left);
	pair<int,int> rightAns = heightDiameter(root->right);
	
	//finding the left diameter,left height ,right diameter,right height 
	//from leftAns and rightAns in ld,lh,rd,rh
	int ld = leftAns.second;
	int lh = leftAns.first;
	int rd = rightAns.second;
	int rh = rightAns.first;
	
	//this is the final height by adding 1 becouse of root node
	int height = 1 + max(lh, rh);
	
	//as discussed earlier diameter is the maximum of the height and ld and rd
	int diameter = max(lh + rh, max(ld, rd));
	
	//creating p object of pair class to return
	pair<int, int> p;
	p.first = height;
	p.second = diameter;
	return p;
}
//This function prints the binary tree by taking root of tree
void print(BinaryTreeNode<int>* root){
	//base case of recursion
	if(root==NULL){
		return;
	}
	//printing data of root node
	cout<<root->data<<":";
	//printing left and right child of root node
	if(root->left !=NULL){
		cout<<"L "<<root->left->data<<",";
	}
	if(root->right !=NULL){
		cout<<"R "<<root->right->data;
	}
	cout<<endl;
	//calling on left and right subtree of root node
	print(root->left);
	print(root->right);
}

//This function take input from the user level wise
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

//main function that drives the program

//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1  this is the sample tree input for the tree
				
//					 1
//				  /  \ \
//				 2   3  4
//              /\  /\
//			   5  6 7 8
//					   \
//						9	

int main()
{
	BinaryTreeNode<int>* root=takeInputLevelWise();
	cout<<"Diameter of given tree from first approach is :"<<diameter(root)<<endl;
	
	pair<int,int> p =heightDiameter(root);
	cout<<"Diameter of given tree from second approach is :"<<p.second<<endl;
}

//Time Complexities:-

	//Time complexity of diameter() function is O(n*h) where h is the height of the tree.the recurrence relation is T(n) = 2T(n/2) +Kn
	
	//Time complexity of heightDiameter() function is O(n).
