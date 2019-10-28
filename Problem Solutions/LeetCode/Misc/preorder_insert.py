"""
Return the root node of a binary search tree that matches the given preorder traversal.
(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, 
and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, 
then traverses node.left, then traverses node.right.)

Example 1:
Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
"""



# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

        
class Solution:
    def preorder_insert(self, T: TreeNode, data):
        if T is None:
            return
        if T.val < data:
            if T.right is None: 
                T.right = TreeNode(data)
            else:
                self.preorder_insert(T.right, data)
        if T.val > data:
            if T.left is None: 
                T.left = TreeNode(data)
            else:
                self.preorder_insert(T.left, data)
            
        
        
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        T = TreeNode(preorder[0])
        for x in range(1, len(preorder)):
            self.preorder_insert(T, preorder[x])
        return T
        