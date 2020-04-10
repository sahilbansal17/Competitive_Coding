/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        // {node, level}
        queue<pair<TreeNode*, int>> my_queue;
        my_queue.push({root, 1});
        
        // sum of nodes at each level
        vector<int> sum_nodes; // size = 0
        
        // visited vector/map
        map<TreeNode*, int> visited;
        visited[root] = 1;
        
        int max_sum = root->val;
        int res_level = 1; // level with max sum (if multiple, smallest such level)
        while (!my_queue.empty()) {
            auto front_element = my_queue.front();
            TreeNode* cur_node = front_element.first;
            int node_level = front_element.second;
            
            // add node's value to sum of nodes at its level
            int node_val = cur_node->val;
            if (sum_nodes.size() < node_level) {
                sum_nodes.push_back(node_val);
            } else {
                sum_nodes[node_level - 1] += node_val;
            }
            
            // pop the front element
            my_queue.pop();
            
            // if child exists and not visited
            TreeNode* next_node[2];
            next_node[0] = cur_node->left;
            next_node[1] = cur_node->right;
            for (int i = 0; i < 2; ++i) {
                if (next_node[i] && !visited[next_node[i]]) {
                    my_queue.push({next_node[i], node_level + 1});
                    visited[next_node[i]] = 1;
                }
            }
        }
        for (int levl = 1; levl < sum_nodes.size(); ++levl) {
            if (sum_nodes[levl - 1] > max_sum) {
                max_sum = sum_nodes[levl - 1];
                res_level = levl;
            }
        }
        return res_level;
    }
};