void inorder(Node *root,vector<int>&v)
{
    if(root==NULL)
    return;
    
    inorder(root->left,v);
    v.emplace_back(root->data);
    inorder(root->right,v);
}

void bst(Node *root,vector<int>&v,int &i)
{
    if(root==NULL)
    return;
    
    bst(root->left,v,i);
    root->data=v[i];
    i++;
    bst(root->right,v,i);
}

Node *binaryTreeToBST (Node *root)
{   
    if(root==NULL)
    return NULL;
    
    vector<int> v;
    
    inorder(root,v);
    
    sort(v.begin(),v.end());
    
    int i=0;
    bst(root,v,i);
    
    return root;
}
