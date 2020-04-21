PROBLEM:

Return the root node of a binary search tree that matches the given preorder traversal.
(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and
any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then
traverses node.left, then traverses node.right.)
 
Example 1:
Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]


SOLUTION:


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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        if(preorder.size()==0)
            return NULL;
        
        int value=preorder[0];
        vector<int> smaller,greater;
        
        for(int i=1;i<preorder.size();i++)
        {
            if(preorder[i]>value)
                greater.push_back(preorder[i]);
            else
                smaller.push_back(preorder[i]);
        }
        
        TreeNode *newnode=new TreeNode(value);
        newnode->left=bstFromPreorder(smaller);
        newnode->right=bstFromPreorder(greater);
        
        return newnode;
        
    }
};
