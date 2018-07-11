#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

// create a node class to define tree structure
class Node{
    public:
        int data;
        Node* left;
        Node* right;
};

//function to create a node of the tree
Node* createNewNode(int data)
{
    // creates new node
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
};

//Performs in order traversal to print all the nodes of binary tree
void inorderTraversal(struct Node* temp){
    //Base Case
    if(temp == NULL)
        return;
    //Recursive Case
    inorderTraversal(temp->left);
    cout << temp->data << " ";
    inorderTraversal(temp->right);
}

bool checkContinuousTree(Node* root){
    //Base Case
    if(root == NULL)
        return true;
    //Tree has only root node
    else if(root->left == NULL && root->right == NULL)
        return true;
    //Left subtree is empty
    else if(root->left == NULL){
        return (abs(root->data - root->right->data) ==1) && checkContinuousTree(root->right);
    }
    //Right subtree is empty
    else if(root->right == NULL){
        return (abs(root->data - root->left->data) && checkContinuousTree(root->left));
    }
    else{
        (abs(root->data - root->left->data)==1) && (abs(root->data - root->right->data)==1)
        && checkContinuousTree(root->left) && checkContinuousTree(root->right);
    }
}

int main(){
    // Building up the tree
    struct Node *root = createNewNode(5);
    root->left        = createNewNode(4);
    root->right       = createNewNode(6);
    root->left->left  = createNewNode(3);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(7);

    //Printing the tree
    cout << "The tree built after inserting the nodes is" << endl;
    inorderTraversal(root);
    cout << endl;

    if(checkContinuousTree(root)){
        cout << "Tree is continuous" << endl;
    }
    else{
        cout << "Tree is not continuous" << endl;
    }
    return 0;
}
/* Time Complexity - O(n) as it recursively visits all nodes
   Space Complexity - O(n) as it is proportional to number of nodes present
*/
