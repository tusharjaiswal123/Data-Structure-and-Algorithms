void helper(Node *root,int k,unordered_map<int,int>&p,int sum,int& ans)
{   
    if(root==NULL)
    return;
    
    if(sum+root->data==k)
    ans++;
    
    ans+=p[sum+root->data-k];
    
    p[sum+root->data]++;
    
    helper(root->left,k,p,sum+root->data,ans);
    helper(root->right,k,p,sum+root->data,ans);
    
    p[sum+root->data]--;
}

int printCount(Node *root,int k)
{
    if(root==NULL)
    return 0;
    
    unordered_map<int,int> p;
    int ans=0;
    
    helper(root,k,p,0,ans);
    return ans;
}
