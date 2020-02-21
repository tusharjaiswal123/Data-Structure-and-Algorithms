int helper(Node * root,int curr,int reset)
{
    static int toplevel=-1;
    
    if(reset)
    toplevel=-1;
    
    if(root->left==NULL && root->right==NULL)
    {
        if(toplevel==-1)
        {
        toplevel=curr;
        return true;
        }
        
        else if(toplevel==curr)
        return true;
        
        else
        return false;
    }
    
    int left=true,right=true;
    
    if(root->left)
    left=helper(root->left,curr+1,false);
    
    if(root->right)
    right=helper(root->right,curr+1,false);
    
    if(left==false || right==false)
    return false;
    
    return true;
    
}

bool check(Node *root)
{
    if(root==NULL)
    return true;
    
    return helper(root,0,true);
}
