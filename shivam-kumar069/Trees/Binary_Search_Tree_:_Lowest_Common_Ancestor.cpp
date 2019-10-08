// A C++ solution to the problem: https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem
// This is a general solution to any binary tree (not limited to binary search tree)
// Complexity: O(n)

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
//##################### The important part ######################################
    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
        struct elm{
            Node *ptr;
            int state;
        };

        stack<elm> s1, s2;

        elm temp;
        temp.ptr = root;
        temp.state = 0;

        s1.push(temp);
        s2.push(temp);

        while(!s1.empty()){
            if(s1.top().ptr->data == v1){
                break;
            }

            if(s1.top().state==0){
                if(s1.top().ptr->left==NULL){
                    s1.top().state=1;
                    continue;
                }
                s1.top().state=1;
                elm tmp1;
                tmp1.ptr = s1.top().ptr->left;
                tmp1.state = 0;
                s1.push(tmp1);
            }
            else if(s1.top().state==1){
                if(s1.top().ptr->right==NULL){
                    s1.top().state=2;
                    continue;
                }
                s1.top().state=2;
                elm tmp1;
                tmp1.ptr = s1.top().ptr->right;
                tmp1.state = 0;
                s1.push(tmp1);
            }
            else{
                s1.pop();
            }
        }


        while(!s2.empty()){
            if(s2.top().ptr->data == v2){
                break;
            }

            if(s2.top().state==0){
                if(s2.top().ptr->left==NULL){
                    s2.top().state=1;
                    continue;
                }
                s2.top().state=1;
                elm tmp1;
                tmp1.ptr = s2.top().ptr->left;
                tmp1.state = 0;
                s2.push(tmp1);
            }
            else if(s2.top().state==1){
                if(s2.top().ptr->right==NULL){
                    s2.top().state=2;
                    continue;
                }
                s2.top().state=2;
                elm tmp1;
                tmp1.ptr = s2.top().ptr->right;
                tmp1.state = 0;
                s2.push(tmp1);
            }
            else{
                s2.pop();
            }
        }

        if(s1.empty() || s2.empty()){
            return NULL;
        }

        vector<Node*> V1;
        vector<Node*> V2;

        while(!s1.empty()){
            V1.push_back(s1.top().ptr);
            s1.pop();
        }
        while(!s2.empty()){
            V2.push_back(s2.top().ptr);
            s2.pop();
        }

        Node *res;
        while(V1.back()==V2.back()){
            res = V1.back();
            V1.pop_back();
            V2.pop_back();
        }

        return res;
    }
 //###############################################################################

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
