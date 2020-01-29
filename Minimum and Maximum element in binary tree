int findMax(struct node* root)
{   
    if(root==NULL)
    return INT_MIN;
    
    
    return max({root->data,findMax(root->left),findMax(root->right)});
}

// Returns minimum value in a given Binary Tree



int findMin(struct node* root)
{
    if(root==NULL)
    return INT_MAX;
    
    return min({root->data,findMin(root->left),findMin(root->right)});
}
