PROBLEM:

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42



SOLUTION:


class Solution {
public:
    
    int sum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        return max({0,sum(root->left)+root->val,sum(root->right)+root->val});
    }
    
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return INT_MIN;
        
        return max({sum(root->left)+sum(root->right)+root->val,maxPathSum(root->left),maxPathSum(root->right)});
        
    }
};
