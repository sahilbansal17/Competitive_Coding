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

//function to insert a new node into the tree
void insertNewNode(Node* root, int new_data){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* root = q.front();
        q.pop();

        if(root->left == NULL){
            root->left = createNewNode(new_data);
            break;
        }
        else
            q.push(root->left);

        if(root->right == NULL){
            root->right = createNewNode(new_data);
            break;
        }
        else
            q.push(root->right);
    }
}

/*function to delete last entered node to take place over vacancy created by deleted node
This is done so as to maintain the tree so best option option is to delete last node
in level order traveral of the tree*/
void deleteLastEnteredNode(Node* root, Node* del){
    // maintain a queue to store the references of child nodes to access them later
    queue<Node*> q;
    q.push(root);
    Node* temp1;
    while(!q.empty()){
        temp1 = q.front();
        q.pop();
        if (temp1->left)
        {
            if (temp1->left == del)
            {
                temp1->left = NULL;
                delete(del);
                return;
            }
            else
                q.push(temp1->left);
        }

        if (temp1->right)
        {
            if (temp1->right == del)
            {
                temp1->right = NULL;
                delete(del);
                return;
            }
            else
                q.push(temp1->right);
        }
    }
}
//function to delete the node with the given key
void deleteNode(Node* root,int delete_key){
    queue<Node*> q;
    q.push(root);
    Node* temp;
    Node* del = NULL;
    /* traverse through the tree to find node which has data same as
     delete_key value provided by user */
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->data == delete_key){
            del = temp;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    // Store the data of the last node and replace the value of data for node to delete
    del->data = temp->data;
    deleteLastEnteredNode(root,temp);
}

//function to find the height of the tree
int findHeight(Node* root){
    // Base Case
    if(root == NULL){
        return -1;
    }
    // Recursive Case
    int left_subtree = findHeight(root->left);
    int right_subtree = findHeight(root->right);
    return max(left_subtree,right_subtree) + 1;
}

int main(){

    Node* root = createNewNode(5);
    root->left = createNewNode(34);
    root->right = createNewNode(4);
    root->left->left = createNewNode(25);
    root->left->right = createNewNode(55);
    root->right->left = createNewNode(14);

    //traversal to print all the nodes
    cout << "The binary tree created is " << endl;
    inorderTraversal(root);
    cout << endl;

    //insertion
    int new_data;
    cout << "Enter the data you want to enter to new node" << endl;
    cin >> new_data;
    insertNewNode(root,new_data);
    cout << "After inserting new node the final binary tree formed is" << endl;
    inorderTraversal(root);
    cout << endl;

    //deletion
    int delete_key;
    cout << "Before deleting the key the the tree is " << endl;
    inorderTraversal(root);
    cout << endl;
    cout << "Enter the element you want to delete from the tree"<< endl;
    cin >> delete_key;
    deleteNode(root,delete_key);
    cout << "After deleting the key the final the tree is" << endl;
    inorderTraversal(root);
    cout << endl;

    //calculate height
    cout << "The height of the tree is" << endl;
    cout << findHeight(root);
    return 0;
}
/* Time Complexity
    Insertion operation takes O(n) as insertion of each node takes O(1) time and there are n
    nodes therefore insertion takes O(n) time
    Deletion operation takes O(2*n) which is basically O(n) since we have to find the last node inserted
    before the node to be deleted so two different tasks
    For level order traversal time complexity is O(n) since nodes are put in queue and traversed
    one by one using FIFO structure

   Space Complexity
    Space Complexity for each node we n*(2*(size of pointer) + size of data)
    where n is the no of elements and queue of size O(n/2) in worst case
    therefore overall space complexity can be considered to be O(n) in insertion as well as deletion
*/
