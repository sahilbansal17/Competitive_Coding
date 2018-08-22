//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to implement Binary search tree class with th efollowing features:-
	//Constructor
	//Destructor
	//Insert function (that inserts the element in the tree)
	//Delete function (that deletes the node)
	//print function to print the output tree
#include<iostream>

using namespace std;

//BinaryTreeNode class because BST is a type of Binary tree
template<typename T>
class BinaryTreeNode{
	public:
		T data;
		BinaryTreeNode *left;
		BinaryTreeNode *right;
		//constructor that initializes the object during reation
	    BinaryTreeNode(T data){
	    	this->data = data;
	    	left =NULL;
	    	right =NULL;
		}
		//Destructor helps in deleting of tree when needed
		~BinaryTreeNode(){
			delete left;
			delete right;
		}
};

//BST class is the class whic we need to implement
class BST{
	//a private variable of type BinaryTreeNode
	BinaryTreeNode<int>*root;
	
	public:
		//constructor that initializes the root to NULL during creation
		BST(){
			root=NULL;
		}
		//Destructor helps in deleting of tree when needed
		~BST(){
			delete root;
		}
	
	private:
		//private helper function to insert function with additional input parameter
		BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int>*root){
			//base case of recursion is that is the tree is empty
			//and the data to insert is goin to be the first element
			//then just create an node and return it
			if(root==NULL){
				BinaryTreeNode<int>* ans = new BinaryTreeNode<int>(data);
				return ans;
			}
			//if the input data is greater than the root data 
			//than node should be inserted on the right subtree 
			if(data>root->data){
				root->right = insert(data,root->right);
			}
			//if the input data is less than the root data 
			//than node should be inserted on the left subtree
			else if(data<root->data){
				root->left =insert(data,root->left);
			}
			
			//returning the root node of BST tree
			return root;
		}
	public:
		//insert() function takes the data as parameter and add it to tree
		void insert(int data){
			//calling of helper function with one more input parameter i.e root
			//changing thr root of the existing tree to the result get from insert function
			this->root=insert(data,this->root);
		}
	//private helper function to deleteData function with additional input parameter
	private:
		BinaryTreeNode<int>* deleteData(int data,BinaryTreeNode<int>*root){
			//base case if the root =NULL then there is no tree then return NULL
			if(root==NULL){
				return NULL;
			}
			
			//if the data to be deleted is greater than the root->data then
			//it will be found in the right subtree 
			//so calling recursion on right subtree and returning the root
			if(data>root->data){
				root->right = deleteData(data,root->right);
              return root;
			}
			//if the data to be deleted is less than the root->data then
			//it will be found in the left subtree 
			//so calling recursion on left subtree and returning the root
			else if(data<root->data){
				root->left =deleteData(data,root->left);
              return root;
			}
			//else if data is equal to the root->data then cases arrises see in this else block 
			else{
				//there is no left and right subtree of the root node
				//than tjust delete the root node and return NULL 
				//because there is no tree left any more
				if(root->left ==NULL && root->right ==NULL){
					delete root;
					return NULL;
				}
				//if there is no left subtree of root node
				//only right subtree is there than the data of root node
				//will equl to the data of right node and returning them
				//deleting the root node
				else if(root->left ==NULL){
					BinaryTreeNode<int>* temp = root->right;
					root->right =NULL;
					delete root;
					return temp;
				}
				//if there is no right subtree of root node
				//only left subtree is there than the data of root node
				//will equal to the data of left node and returning them
				//deleting the root node
				else if(root->right ==NULL){
					BinaryTreeNode<int>* temp = root->left;
					root->left =NULL;
					delete root;
					return temp;
				}
				//this block of statement runs when root node has bot left and right subtree
				else{
					//saving the root->right in temp variable
					BinaryTreeNode<int>* temp = root->right;
					//the motive of this while loop is to find the minimum data value node on right subtree
					while(temp->left!=NULL){
						temp = temp->left;
					}
					//storing the min data of right subtree as rightMin
					int rightMin = temp->data;
					//if both right and left subtree are there for the root node
					//than we need to find the minimum data value in the right subtree and make the root data
					//equal to that minimum value
					root->data = rightMin;
					//deleting the required node to be deleted
					root->right=deleteData(rightMin,root->right);
					//returning the root node
					return root;
				}
			}
		}
	public:
		//deleteData() function takes the data as parameter and remove it from tree
		void deleteData(int data){
			root = deleteData(data,root);
		}
	
	//private helper function to hasData function with additional input parameter	
	private:
		//this function for the particular data value in the tree and return true/false if available or not
		bool hasData(int data,BinaryTreeNode<int>* node){
			//base case if the node =NULL then there is no data in tree then return flase
			if(node==NULL){
				return false;
			}
			// if node data is equal to the data to be search for than i=return the true
			if(node->data == data){
				return true;
			}
			//if the data to be found than is less than the node->data
			//than there is no point of finding the the value in in right subtree
			//therefore calling recursion on left subtree
			else if(data < node->data){
				return hasData(data,node->left);
			}
			//if the data to be found than is greater than the node->data
			//than there is no point of finding the the value in in left subtree
			//therefore calling recursion on right subtree
			else{
				return hasData(data,node->right);
			}
		}
	public:	
		//hasData() function takes the data as parameter and return true and false accordingly
		bool hasData(int data){
			return hasData(data,root);
		}
		
	//private helper function to printTree function with additional input parameter
	private:
		//this printTree() function prints the tree to the output terminal
		void printTree(BinaryTreeNode<int>* root){
			//base case if the root =NULL then there is no data in tree so nothing to be printed therefore just return
			if(root==NULL){
				return;
			}
			//printing the root->data with leading colon
			cout<<root->data<<":";
			//if root->left is not null then printing it's child in same line
			if(root->left !=NULL){
				cout<<"L "<<root->left->data<<",";
			}
			//if root->right is not null then printing it's child in same line
			if(root->right !=NULL){
				cout<<"R "<<root->right->data;
			}
			cout<<endl;
			//calling recursion on both left and right subtree
			printTree(root->left);
			printTree(root->right);
		}
	
	public:
		//printTree() function takes no parameter and prints the the tree
		void printTree(){
			printTree(root);
		}
};
//main function that drives the program
int main()
{
	//creating the a BST tree b
	BST b;
	b.insert(10);
	b.insert(5);
	b.insert(20);
	b.insert(7);
	b.insert(3);
	b.insert(18);
	
	//after inserting the above elements the resulting tree is like following:
	//                  10
	//                 /  \
	//                5    20
	//               / \   /
	//              3   7 18
	
	//printing the above tree by calling printTree() function
	b.printTree();
	
	//deleting 20 node by calling deleteData() function
	b.deleteData(20);
	cout<<"After deleting 20 node the tree becomes:"<<endl;
	//printing the tree again after deleting 20 from tree
	//resultant tree after deleting 20 node is:
	//                   10
	//                  /  \
	//                 5   18
	//                / \
	//               3   7
	b.printTree();
	
	//calling hasData() function to find 10 data node in the tree
	if(b.hasData(10)){
		cout<<"10 exists in the the tree"<<endl;
	}
	else{
		cout<<"10 doesn't in the tree"<<endl;
	}
}
