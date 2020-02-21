int height(Node *root)
{
    if(root==NULL)
    return 0;
    
    return max(height(root->left),height(root->right))+1;
}

int sumOfLongRootToLeafPath(Node* root)
{   
    if(root==NULL)
    return 0;
    
    if(height(root->left)>height(root->right))
    return root->data+sumOfLongRootToLeafPath(root->left);
    
    else if(height(root->right)>height(root->left))
    return root->data+sumOfLongRootToLeafPath(root->right);
    
    else
    return root->data+max(sumOfLongRootToLeafPath(root->left),sumOfLongRootToLeafPath(root->right));
	
}
