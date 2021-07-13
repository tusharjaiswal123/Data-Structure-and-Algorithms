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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans;
public:
    
    int helper(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        
        int l = helper(root->left);
        int r = helper(root->right);
        
        ans = max(ans,l+r+root->val);
        
        return max(0,max({l,r,0})+root->val);
    }
    
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        ans = INT_MIN;
        helper(root);
        
        return ans;
    }
};
