/*  Here, n elements are inserted and O(n) time is taken
    to insert each element in the BST. Hence, we
    end up with an overall time complexity of O(n*n), worst case.

    In general however, overall time complexity is O(n*h) where
    h is the height of the tree.
    Again, n = 2^( h + 1 ) - 1 for a tree.
    Hence, time complexity can be assumed to be O(n*log(n)) generally.
*/

#include <iostream>
using namespace std;

struct BSTnode{
    int data;
    BSTnode* left;
    BSTnode* right;
};

struct ListNode{
    int data;
    ListNode* next;
};

BSTnode* createBSTNode(int data){
    BSTnode *newNode = new BSTnode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void createListNode(ListNode **head ,int data){
    ListNode *newNode = new ListNode();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

BSTnode* insertBSTNode(BSTnode* node ,int data){
    if(node == NULL)
        return createBSTNode(data);

    if(data < node->data)
        node->left = insertBSTNode(node->left, data);

    else if( data > node->data)
        node->right = insertBSTNode(node->right, data);

    return node;
}

BSTnode* makeTree( ListNode* trav ){

    BSTnode *root = NULL;

    root = insertBSTNode(root, trav->data);
    trav = trav->next;

    while( trav != NULL ){
        insertBSTNode(root, trav->data);
        trav = trav->next;
    }

    return root;
}

void inorder(BSTnode* node){

    if(node!=NULL){
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
}


int main(){
    int n;
    cout << "Enter number of nodes" << endl;
    cin>>n;

    cout << "Enter values to be put in the linked list " << endl;
    int i;

    ListNode *head = NULL;
    int val;

    for(i = 0; i < n; i ++){
        cin>>val;
        createListNode(&head, val);
    }

    //Linked list formed

    BSTnode* root = makeTree(head);
    inorder(root);

    return 0;
}

