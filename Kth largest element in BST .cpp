void  revInorder(Node *root,int k,int &c)
{
    if(root==NULL || c>=k)
    return;
    
    revInorder(root->right,k,c);
    c++;
    
    if(c==k)
    {
        cout<<root->key<<endl;
        return;
    }
    revInorder(root->left,k,c);
}
void kthLargest(Node *root, int k)
{
    if(root==NULL)
    return;
    
    int c=0;
    revInorder(root,k,c);
    
    
}
