# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if (root == p or root == q or root is None): return root 
        # if(root==p or root==q): return root;
        left = self.lowestCommonAncestor(root.left,p,q);
        right = self.lowestCommonAncestor(root.right,p,q);
        if(left is not None and right is not None): return root;
        
        if left is not None: return left
        elif right is not None: return right
        return None;
        
        