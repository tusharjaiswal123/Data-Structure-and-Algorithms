int height(Node* node)
{
    if(node==NULL)
    return 0;
    
    int l,r;
    l=height(node->left);
    r=height(node->right);
    
    return max(l,r)+1;
}
