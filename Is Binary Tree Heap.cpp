bool isHeap(Node * tree)
{
    if(tree==NULL)
    return true;
    
    int k=tree->data;
    
    if(tree->left==NULL && tree->right==NULL)
    return true;
    
    else if(tree->left!=NULL && tree->right!=NULL)
    {
        if(k<(tree->left)->data || k<(tree->right)->data )
        return false;
    }
    
    else if(tree->left==NULL)
    {
        if(k<(tree->right)->data)
        return false;
    }
    
    else if(tree->right==NULL)
    {
        if(k<(tree->left)->data)
        return false;
    }
    
    if(!(isHeap(tree->left)) || !(isHeap(tree->right)))
    return false;
    
    return true;
    
}
