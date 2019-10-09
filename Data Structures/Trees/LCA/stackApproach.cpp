#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

stack<int> ST;

Node* newNode(int value)
{
    Node *root = new Node;
    root->data = value;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void inorder(Node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void findpathBST(Node *root, int num)
{
    if(root == NULL)
        return;
    if(root->data == num)
    {
        ST.push(root->data);
        return;
    }
    if(num < root->data)
        findpathBST(root->left, num);
    if(!ST.empty())
    {
        ST.push(root->data);
        return;
    }
    if(num > root->data)
        findpathBST(root->right, num);
    if(!ST.empty())
    {
        ST.push(root->data);
        return;
    }
}

void findLCAinBST(Node *root, int num1, int num2)
{
    stack<int> st1, st2;
    int lcaValue;

    findpathBST(root, num1);
    st1 = ST;
    while(!ST.empty())
        ST.pop();
    findpathBST(root, num2);
    st2 = ST;

    while(st1.top() == st2.top())
    {
        lcaValue = st1.top();
        st1.pop();
        st2.pop();
    }

    cout<<endl<<"LCA of BST is: "<<lcaValue<<endl;
}

stack<int> findpathBTree(Node* root, int num)
{
    stack<int> temp;
    if(root == NULL)
        return temp;
    if(root->data == num)
    {
        stack<int> t;
        t.push(root->data);
        return t;
    }
    temp = findpathBTree(root->left, num);
    if(!temp.empty())
    {
        temp.push(root->data);
        return temp;
    }
    temp = findpathBTree(root->right, num);
    if(!temp.empty())
    {
        temp.push(root->data);
        return temp;
    }
    return temp;
}

void findLCAinBTree(Node *root, int num1, int num2)
{
    stack<int> st1, st2;
    int lcaValue;

    st1 = findpathBTree(root, num1);
    cout<<endl;
    st2 = findpathBTree(root, num2);

    while((!st1.empty()&&!st2.empty()) && (st1.top() == st2.top()))
    {
        lcaValue = st1.top();
        st1.pop();
        st2.pop();
    }

    cout<<endl<<"LCA of B-Tree is: "<<lcaValue<<endl;
}

int main()
{
    int node1, node2;

    //bst
    Node *bstroot = newNode(16); 
    bstroot->left        = newNode(7); 
    bstroot->right       = newNode(18); 
    bstroot->left->left  = newNode(3); 
    bstroot->left->right = newNode(9);
    bstroot->left->right->left = newNode(8); 
    bstroot->left->right->right  = newNode(12);

    //binary tree
    Node *broot = newNode(1); 
    broot->left        = newNode(2); 
    broot->right       = newNode(3); 
    broot->left->left  = newNode(4); 
    broot->left->right = newNode(5);
    broot->left->right->left = newNode(6); 
    broot->left->right->right  = newNode(7);

    cout<<"BST inorder: ";
    inorder(bstroot);
    cout<<endl;

    cout<<"BTree inorder: ";
    inorder(broot);
    cout<<endl;

    cout<<endl<<"****FOR BST****"<<endl;
    cout<<"Enter the node1: ";
    cin>>node1;
    cout<<"Enter the node2: ";
    cin>>node2;
    findLCAinBST(bstroot, node1, node2);

    cout<<endl<<"****FOR B-Tree****"<<endl;
    cout<<"Enter the node1: ";
    cin>>node1;
    cout<<"Enter the node2: ";
    cin>>node2;
    findLCAinBTree(broot, node1, node2);

    return 0;
}

//contributed by Sathvik S
