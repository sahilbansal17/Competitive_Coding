/*  Since it is quite a hassle to ask the user to enter the
    nodes of the tree one by one, the following program
    takes a sample tree in the main function.

    The sample trees are -
    Tree 1 (Parent):
            10
           /  \
          8    14
         / \   / \
        9   6 2   12

    Tree 2 (Sub):
           14
          /  \
         2   12

    The time complexity for the given program is O(m*n), where
    m and n are the number nodes present in the respective trees.
*/

#include <iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* createNode(int data){
    node* newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

bool checkIdentical( node *froot, node *sroot){
    //Checks if the parent tree with the current root is same as the supposed sub tree for all elements

    if( froot == NULL && sroot == NULL)
        return true;

    if( froot == NULL || sroot == NULL )
        return false;

    return (froot->data == sroot->data && checkIdentical(froot->left, sroot->left) && checkIdentical(froot->right, sroot->right) );
}

bool searchSub(node* root, node* sroot){
    //To search for the subtree within the tree
    //Return true if found, else recurs to right and left
    //subtrees to check further, like pre-order traversing.

    if(root == NULL)
        return false;

    if(sroot == NULL)
        return true;

    //Base cases
    //Null subtree is a universal sub tree

    if(checkIdentical(root, sroot))
        return true;

    return (searchSub(root->left, sroot) || searchSub(root->right, sroot) );

}

int main(){

    //Parent tree
    node *root = createNode(10);
    root->left = createNode(8);
    root->right = createNode(14);
    root->left->left = createNode(9);
    root->left->right = createNode(6);
    root->right->left = createNode(2);
    root->right->right = createNode(12);

    //Subtree
    node *sroot = createNode(14);
    sroot->left = createNode(2);
    sroot->right = createNode(12);

    if(searchSub(root, sroot))
        cout<<"Subtree found";
    else
        cout<<"Not a subtree";

    return 0;
}
