#include<iostream>
using namespace std;

//Single node of a tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

//Class functions declaration
class BST {
    public:
        struct node* insertion(int ,struct node*);
        void inorder(struct node*);
        void preorder(struct node*);
        void postorder(struct node*);

        struct node* search(int, struct node*);

        struct node* minValue(struct node*);
        struct node* deletion(int, struct node*);
};

//-------------------DRIVER CODE--------------------

int main() {
    struct node *root = NULL;    //Initializing root as NULL
    BST bst;

    // The tree is like:
    //     5
    //     /\
    //    4  9
    //   /   /\
    //  1   7  11
    //   \
    //    3

    root =  bst.insertion(5, root);    //First insertion becomes root
    bst.insertion(4, root);
    bst.insertion(9, root);
    bst.insertion(1, root);
    bst.insertion(7, root);
    bst.insertion(11, root);
    bst.insertion(3, root);

    //This insertion is for duplicate node
    bst.insertion(4,root);

    //Tree traversal
    cout<<"Displaying the tree:"<<endl;
    cout<<"Inorder: "; bst.inorder(root);
    cout<<endl;
    cout<<"Preorder: "; bst.preorder(root);
    cout<<endl;
    cout<<"Postorder: "; bst.postorder(root);
    cout<<endl;

    //Searching for key
    int key;
    cout<<"Enter key to search: "; cin>>key;
    bst.search(key, root);

    //Deleting for key
    cout<<"Enter key to delete: "; cin>>key;
    root = bst.deletion(key, root);
    cout<<"Inorder: "; bst.inorder(root);    //Displaying tree in inorder after deletion
    cout<<endl;

    return 0;
}

//Function Definitions:

//-------------------INSERTION--------------------

//O(n) worst case, when a BST is in form of a linked list.
//T(n)=T(1)+k, where 2^k = n. Hence k = log n
//Average complexity is O(log n), as it keeps recurring in left/right sub-trees

struct node* BST::insertion(int x, struct node *root) {
    //Creating new node to insert
    struct node *p = new struct node;
    p->data = x;    //Data of the node equal to argument x
    p->left = p->right = NULL;

    //If tree is empty
    if(root==NULL) {
        cout<<"Node inserted."<<endl;
        return p;
    }

    //If value is less than data of node pointed by 'root', goes to the left sub-tree
    if(p->data < root->data) {
        root->left = insertion(x,root->left);
    }

    //If value is more, goes to the right sub-tree
    else if(p->data > root->data) {
        root->right = insertion(x, root->right);
    }

    //If value is equal, node already exists
    else if(p->data == root->data) {
        cout<<"Node already present!"<<endl;
    }

    //Returns the original root node
    return root;
}

//-------------------TRAVERSAL--------------------

// Time complexity of all the traversals is O(n), where n is number of nodes
// This is because the algorithm needs to visit every node of the tree exactly once

//Recurs in left sub-tree of current node
//After encountering null, prints the data, then recurs in right sub-tree
void BST::inorder(struct node *root) {
    if(root == NULL) return;
    inorder(root->left);    //Recursion in left sub-tree
    cout<< root->data << " ";    //Prints the data of node
    inorder(root->right);    //Recursion in right sub-tree
}

//Similar to above, just prints data first, then recurs to left and then right
void BST::preorder(struct node *root) {
    if(root == NULL) return;

    cout<< root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//Recurs to left, then right, then prints data
void BST::postorder(struct node *root) {
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout<< root->data << " ";
}

//-------------------SEARCH--------------------

//O(n) worst case, when a BST is in form of a linked list.
//T(n)=T(1)+k, where 2^k = n. Hence k = log n
//Thus complexity is O(log n), as it keeps recurring in left/right sub-trees

struct node* BST::search(int x, struct node *root) {
    //If NULL is reached, the node does not exist
    if(root==NULL) {
        cout<<"Node not found!"<<endl;
        return root;
    }

    //Satisfies when x equals data of the current node
    if(x == root->data) {
        cout<<"Node found!"<<endl;
        return root;
    }
    //Search is called until any of the above two conditions are satisfied
    //Goes to left sub-tree and calls search again
    if(x < root->data) {
        return search(x,root->left);
    }

    //Goes to right sub-tree and calls search again
    if(x > root->data) {
        return search(x, root->right);
    }
}

//--------------------DELETION--------------------

//This is used to return the node with least value in a subtree with root node 'nodep'
//When used to a node->right, it becomes its inorder successor
struct node* BST::minValue(struct node *nodep) {
    struct node *p = nodep;

    //p keeps going to left until NULL
    while(p->left !=NULL){
        p = p->left;
    }
    return p;    //Returns the minValue node.
}

//O(n) worst case, when a BST is in form of a linked list.
//T(n)=T(1)+k, where 2^k = n. Hence k = log n
//Thus complexity is O(log n), as it keeps recurring in left/right sub-trees

//CASE: When node to be deleted has no child, it gets deleted directly, making the corresponding left/right value in parent NULL
//CASE: When node has one child, eg. left; its parent's left should point to the child, and node gets deleted
//CASE: When node has both children, it copies inorder successor's content and puts it in place of node to be deleted
struct node* BST::deletion(int x, struct node *root) {
    //If NULL is reached, the node does not exist
    if(root == NULL) {
        cout<<"Node not found.";
        return root;
    }
    //if x < data of current node
    //Goes to left sub-tree and calls deletion again
    if(x < root->data)
        root->left = deletion(x, root->left);    //Returning node gets pointed by the root's left

    //if x > data of current node
    //Goes to right sub-tree and calls deletion again
    else if(x > root->data)
        root->right = deletion(x, root->right);    //Returning node gets pointed by the root's right

    //if x equals data of current node
    else {
        //CASE: Node with only one/no child
        
        //If root->left is NULL, root->right gets returned, and 'root' gets deleted
        //If both left & right are NULL, this condition is encountered, 'root' gets deleted, NULL gets returned
        if(root->left == NULL) {
            struct node *temp = root->right;
            delete root;
            return temp;
        }

        //If root->right is NULL, root->left gets returned, and 'root' gets deleted
        else if(root->right == NULL) {
            struct node *temp = root->left;
            delete root;
            return temp;
        }

        //CASE: If 'root' has both left and right nodes

        struct node *temp = minValue(root->right);    //'temp' is inorder successor of 'root'
        root->data = temp->data;    //copies the content of inorder successor
        root->right = deletion(temp->data,root->right);    //Deletes inorder successor
    }
    return root;    //Returns original root
}