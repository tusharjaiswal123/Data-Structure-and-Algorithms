int add(Node * root)
{
    if(root==NULL)
    return 0;
    
    return root->data+add(root->left)+add(root->right);
    
}

bool isSumTree(Node* root)
{   
    if(root==NULL)
    return true;
    
    if(root->left==NULL && root->right==NULL)
    return true;
    
    int left=add(root->left);
    int right=add(root->right);
    
    int total=left+right;
    
    if(root->data==total)
    {
        if(isSumTree(root->left)&&isSumTree(root->right))
        return true;
    }
    return false;
    
}
