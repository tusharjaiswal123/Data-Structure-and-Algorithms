void inorder(Node *root,unordered_set<int>&s,unordered_set<int> &k)
{
    if(root==NULL)
    return;
    
    inorder(root->left,s,k);
    s.insert(root->data);
    if(root->left==NULL && root->right==NULL)
    k.insert(root->data);
    inorder(root->right,s,k);
}

bool isDeadEnd(Node *root)
{
    if(root==NULL)
    return false;
    
    unordered_set<int> s,k;
    s.insert(0);
    
    inorder(root,s,k);
    bool ans=false;
    
    for(auto it=k.begin();it!=k.end();it++)
    {
        if(s.find(*it+1)!=s.end() && s.find(*it-1)!=s.end())
        {
            ans=true;
            break;
        }
    }
    
    return ans;
}
