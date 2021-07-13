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
    int ans;
public:
    int height(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        ans = max(ans,rh+lh);
        return max(rh,lh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        ans = 0;
        height(root);
        
        return ans;
    }
};
