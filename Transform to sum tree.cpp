int k(Node* root)
{   
    if(root==NULL)
    return 0;
    
    int s=root->data;
    
    root->data=k(root->left)+k(root->right);
    
    return (s + root->data);
}

void toSumTree(Node *node)
{   
    k(node);
}
