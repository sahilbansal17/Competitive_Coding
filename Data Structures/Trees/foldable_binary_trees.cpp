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

//Performs inorder traversal to print all the nodes of binary tree
void inorderTraversal(struct Node* temp){
    //Base Case
    if(temp == NULL)
        return;
    //Recursive Case
    inorderTraversal(temp->left);
    cout << temp->data << " ";
    inorderTraversal(temp->right);
}

void createMirrorImage(Node* n)
{
    //Base Case
    if(n == NULL){
        return;
    }
    else{
        //Recursive Case
        Node* temp;
        createMirrorImage(n->left);
        createMirrorImage(n->right);
        //Swapping the left and right of all nodes
        temp = n->left;
        n->left  = n->right;
        n->right = temp;
    }
}

bool checkSimilarStructure(Node *p, Node *q)
{
  if(p == NULL && q == NULL){
        return true;
  }
  //Recursively visits all nodes to check whether they have similar structure
  if(p != NULL && q != NULL && checkSimilarStructure(p->left, q->left) && checkSimilarStructure(p->right, q->right)){
        return true;
  }
  return false;
}

bool checkFoldableTree(Node* root){
    //Base case
    if(root == NULL)
        return true;
    bool ans;
    //Recursive Case
    createMirrorImage(root->left);
    // checks whether two structures are similar or not
    ans = checkSimilarStructure(root->left, root->right);
    // Reverting what is done earlier to restore normal structure of tree
    createMirrorImage(root->left);

    return ans;
}

int main(){
    // Building up the tree
    Node* root = createNewNode(5);
    root->left = createNewNode(10);
    root->right = createNewNode(15);
    root->left->left = createNewNode(20);
    root->left->right = createNewNode(25);
    root->right->left = createNewNode(30);
    root->right->right = createNewNode(35);

    cout << "The tree built after inserting the nodes is" << endl;
    inorderTraversal(root);
    cout << endl;

    if(checkFoldableTree(root)){
        cout << "Tree is foldable" << endl;
    }
    else{
        cout << "Tree is not foldable" << endl;
    }
    return 0;
}
/* Time Complexity
   To check whether the tree is foldable or not is O(n) as it depends upon the number of nodes
   in the tree
   Space Complexity is also O(n)
   Actually it is the createMirrorImage function behind which is taking up O(n) time
   create similar structure is also a recursive structure which recursively traverses throught all
   nodes in the tree
*/
