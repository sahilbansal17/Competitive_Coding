//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to implement Generic Tree data structure
//with following custom function:
	// Level Wise Take Input Function
  	//Level Wise Print Output Function
  	//Counting Number Of Nodes Function
  	//Sum Of Data Of all Nodes Function
  	//Maximum Data Node Function
  	//Count Leaf Node Function
  	//Find Height of Tree Function
  	//Print at Depth/Level Function
  	//Pre Order Traversal
  	//Post Order Traversal
  	
  	
#include<iostream>
#include<queue>

using namespace std;

//template for the generic datatype
template <typename T>

//GenericTreeNode class for generic tree 
class GenericTreeNode{
	public:
		//T type data of node
		T data;
		//vector children of type GenericTreeNode to store the address of its children nodes 
		vector<GenericTreeNode<T>*> children;
		//constructor to initialize the data at starting
		GenericTreeNode(T data){
			this->data = data;
		}
		//destructor to delete all the tree
		~GenericTreeNode(){
			//this for loop is used for deleting the chicldrens of the root 
			//as if i delete only the root then all the remaining childrens left undeleted
			for(int i=0;i<children.size();i++){
				delete children[i];
			}
		}
		
};

//takeInput() function takes the input from the user level wise
template <typename T>
GenericTreeNode<T>* takeInput(){
	//prompt the user to enter the starting root data
	T rootData;
	cout<<"Enter root data :"<<endl;
	cin>>rootData;
	
	//created an object of class GenericTreeNode root with input of rootData
	GenericTreeNode<T>* root = new GenericTreeNode<T>(rootData);
	
	//made a queue  of type GenericTreeNode which will help in taking the inputs from the user levelwise
	//it accounts for all the pending nodes that are not yet taken input of
	queue<GenericTreeNode<T>*>pendingNodes;
	
	//pushed the root in the pendingNodes queue because
	//it's childrens are yet to be added
	pendingNodes.push(root);
	
	//this loop works until there is any pending node left to be taken input of
	while(pendingNodes.size()!=0){
		
		//created an object of class GenericTreeNode front which takes the front element of pendingNodes queue
		GenericTreeNode<T>* front = pendingNodes.front();
		//clearing the front element from pendingNodes queue because we have saved in front object
		pendingNodes.pop();
		
		//prompts the user to enter the number of childrens of front element
		cout<<"Enter the number of childrens of "<<front->data<<" :";
		int numChild;
		cin >>numChild;
		
		//running the for loop for numbe of childrens time to take the inputs
		for(int i=0;i<numChild;i++){
			//prompt the user for entring the data of parcular child
			T childData;
			cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
			cin>>childData;
			
			//created a child object with input childData as data
			GenericTreeNode<T>* child = new GenericTreeNode<T>(childData);
			//connecting the child which user just inputed to the front object 
			//which itself is connected to root  
			front->children.push_back(child);
			//pushing the child in queue which maintains the pendingNodes
			pendingNodes.push(child); 
		}
	}
	//returning the root of the tree 
	return root;
}

//printLevelWise() is a function that prints the data levelwise
//this function takes the root of tree as input parameter 
template <typename T>
void printLevelWise(GenericTreeNode<T>* root){
	//made a queue  of type GenericTreeNode which will help in printing the data levelwise
	//it accounts for all the pending nodes that are not yet printed
	queue<GenericTreeNode<T>*>pendingNodes;
	
	//pushing the root in that pendingNodes queue
	pendingNodes.push(root);
	
	//this loop works until there is any pending node left to be taken input of
	while(pendingNodes.size()!=0){
		//created an object of class GenericTreeNode front which takes the front element of pendingNodes queue
		GenericTreeNode<T>* front = pendingNodes.front();
		//clearing the front element from pendingNodes queue because we have saved in front object
		pendingNodes.pop();
		//printing the data of the front element with colon
		cout<<front->data<<":";
		//this loops run for the children.size() times
		for(int i=0;i<front->children.size();i++){
			//printing the childrens data of of the front node
			cout<<front->children[i]->data;
			//this if statement is for eliminating the comma after last element of the the children
			if(i<front->children.size() - 1){
				cout<<",";
			}
			//creating a child object of GenericTreeNode class which takes the input of children of front 
			GenericTreeNode<T>* child  = front->children[i];
			//pushing the element child to pending Nodes for prining their childrens
			pendingNodes.push(child);
		}
		//next line after every level is printed
		cout<<endl;
	}
}
//countingNumberOfNodes() function returns the total numebr of node in a tree
template <typename T>
int countingNumberOfNodes(GenericTreeNode<T>* root){
	//this is an edge case to tackel the condition if the user gives a null tree in input
	//don't misunderstood it with base case of recurson it's not the base case but an edge case
	if(root==NULL){
		return -1;
	}
	
	//initializing ans variable to 1 because if root is not null there must be atleast one root node 
	int ans =1;
	//calling recursion to all the childrens of given root node
	//and adding the recursion result in ans 
	for(int i=0;i<root->children.size();i++){
		ans+= countingNumberOfNodes(root->children[i]);
	}
	//returning the ans variable which is the number of nodes
	return ans;
}

int sumOfNodes(GenericTreeNode<int>* root){
	//this is an edge case to tackel the condition if the user gives a null tree in input
	//don't misunderstood it with base case of recurson it's not the base case but an edge case
	if(root==NULL){
		return -1;
	}
	//initialize the sum variable to zero which will contain the sum of the data of all nodes
	int sum = 0;
	//putting the root->data in sum 
	sum+=root->data;
	//calling recursion to all the childrens of given root node
	//and adding the recursion result in sum
	for(int i=0;i<root->children.size();i++){
		sum+= countingNumberOfNodes(root->children[i]);
	}
	return sum;
}

GenericTreeNode<int>* maxDataNode(GenericTreeNode<int>* root){
	//this is an edge case to tackel the condition if the user gives a null tree in input
	//don't misunderstood it with base case of recurson it's not the base case but an edge case
	if(root==NULL){
		return 0;
	}
	GenericTreeNode<int>* temp = root;
	
	//calling recursion to all the childrens of given root node
	//and comparing the result from recursion node data to the temp that is 
	//the data of the root node
	//and if the t->data > temp->data then update temp
	for(int i=0;i<root->children.size();i++){
		GenericTreeNode<int>* t = maxDataNode(root->children[i]);
		if(t->data > temp->data){
			temp = t;
		}
	}
	//return the node of max data
	return temp;
}

//this height() function returns the height of the tree
//this returns 1 if theree is no children only a root
template <typename T>
int height(GenericTreeNode<T>* root){
	//initialize temp variable to 0
	int temp = 0;
	
	//calling recursion to all the childrens of given root node
	//and comparing the result from recursion node data to the temp that is 
	//and if the t > temp then update temp
	for(int i=0;i<root->children.size();i++){
		int t=height(root->children[i]);
		if(t>temp){
			temp = t;
		}
	}
	//return temp+1
	return temp+1;
}

// depthOfNode() function prints the elements of the treee of a particular depth from a givenn node
//for example i have taken root node at depth 0 and there childrens are obviously at depth 1 from root
// so if i give the funccion first parameter as root and other as 1 then the children of root  prints
template <typename T>
void depthOfNode(GenericTreeNode<T>* root,int k){
	//base case of recursion
	//if k i.e depth is zero then print the data of that node
	if(k==0){
		cout<<root->data<<" ";
	}
	//calling recursion on all its childrens with input parameters k-1
	//i.e of depth less by one
	for(int i=0;i<root->children.size();i++){
		depthOfNode(root->children[i],k-1);
	}
}

//leafNodes() function returns the total number of leaf nodes of tree
//leaf node is a tree which doesn't have their childrens
template <typename T>
int leafNodes(GenericTreeNode<T>* root){
	//base case of recursion is that if there is no children of the node
	//then return 1 as it is a leaf node 
	if(root->children.size()==0){
		return 1;
	}
	int t=0;
	//calling recursion on all the childrens of the root node
	//and adding the results in t variable
	for(int i=0;i<root->children.size();i++){
		t+=leafNodes(root->children[i]);
	}
	//returning total number of leaf nodes in tree
	return t;
}

//preOrder Traversal of the the tree
template <typename T>
void preOrder(GenericTreeNode<T>* root){
	//as before it is the edge case not base case
	if(root==NULL){
		return;
	}
	
	//printing the data of root node
	cout<<root->data<<" ";
	//calling recursion on all the childrens of the root node
	//recursion helps in printing all the daa elements
	for(int i=0;i<root->children.size();i++){
		preOrder(root->children[i]);
	}
}

//postOrder GenericTreeNode of the tree
template <typename T>
void postOrder(GenericTreeNode<T>* root){
	//as before it is the edge case not base case
	if(root==NULL){
		return;
	}
	
	//calling a recursion on the children of root node
	for(int i=0;i<root->children.size();i++){
		postOrder(root->children[i]);		
	}
	//after calling recursion printing the elements 
	cout<<root->data<<" ";
}

//main function that drives the program

//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0 this is the sample tree input for the tree
				
//					 1
//				  /  \ \
//				 2   3  4
//              /\  /\
//			   5  6 7 8
//					   \
//						9	
		
int main()
{
	//takeinput() function takes the input from the user
	//and made a object of GenericTreeNode root
	GenericTreeNode<int> *root=takeInput<int>();
	
	//printLevelWise() prints the tree level wise
	cout<<"Level Wise printing of tree is is follows"<<endl;
	printLevelWise(root);
	cout<<"Total number of node are : "<<countingNumberOfNodes(root)<<endl;
	
	//please note that sumOfNodes() function and maxDataNode() function will not work 
	//for character or string type datatype 
	cout<<"Summ of the data of all the nodes of tree are : "<<sumOfNodes(root)<<endl;
	cout<<"Data of Maximum data node : "<<maxDataNode(root)->data<<endl;
	cout<<"Height of Tree is : "<<height(root)<<endl;
	
	cout<<"Depth of 1 of the root node is : ";
	depthOfNode(root,1);
	cout<<endl;
	
	cout<<"Total number of leaf nodes of tree is:"<<leafNodes(root)<<endl;
	cout<<"Preorder Traversal is :";
	preOrder(root);
	cout<<endl;
	
	cout<<"Postorder Traversal is :";
	postOrder(root);
	cout<<endl;
	
	//by this statement destructor is called 
	delete root;
}
