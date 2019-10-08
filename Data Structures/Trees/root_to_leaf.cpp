//Given a Binary Tree and a sum s, your task is to check whether there is a root to leaf path in that tree with the following sum 
//link to the question : https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  
  Node(int x){
      data = x;
      left = NULL;
      right = NULL;
  }
};
bool hasPathSum(Node *root, int sum) //function which is suppose to be completed
{
   if(root==NULL)
   return false;
   if(root->left==NULL&&root->right==NULL)
   {
       if(sum==root->data)
       return true;
       return false;
       
   }
   int x=hasPathSum(root->left,sum-root->data);
   int y=hasPathSum(root->right,sum-root->data);
   return x||y;
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     struct Node *root = NULL;
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     int a;
     cin>>a;
     cout<<hasPathSum(root,a)<<endl;
  }
  }
  return 0;
}

