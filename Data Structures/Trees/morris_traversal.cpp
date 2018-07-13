#include<iostream>
#include<queue>
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

// calculating morris traversal
void morrisTraversal(Node* root){
    // initializing current pointer to point to root
    Node* current = root;

    while(current != NULL){
        //checking if left subtree is empty of the current node
        if(current->left == NULL){
            cout << current->data << " ";
            current = current -> right;
        }
        else{
            // calculating the in order predecessor of the current node
            Node* predecessor = current->left;

            while(predecessor -> right != NULL && predecessor->right != current){
                predecessor = predecessor -> right;
            }
            // checking whether we have traversed all the left subtree
            if(predecessor -> right == NULL){
                predecessor -> right = current;
                current = current -> left;
            }
            // removing the in order predecessor pointer and moving current node to right
            else{
                predecessor -> right = NULL;
                cout << current -> data << " ";
                current = current -> right;
            }
        }

    }
}

int main(){
    // creating the tree
    Node* root = createNewNode(5);
    root->left = createNewNode(34);
    root->right = createNewNode(4);
    root->left->left = createNewNode(25);
    root->left->right = createNewNode(55);
    root->right->left = createNewNode(14);

    //calling the morris traversal algorithm to print all the nodes
    cout << "The binary tree created after morris traversal is " << endl;
    morrisTraversal(root);
    cout << endl;

}
/* Time Complexity of Morris Traversal is O(n)
 Space Complexity of Morris Traversal is O(n) as it does not involve any extra
 space other than the nodes */
