1.print left boundry elements without leaves
2.print leaves from left to right
3.print right boundry elements without leaves

void printleft(Node* root)
{
    if(root==NULL)
    return;
    
    if(root->left)
    {
        cout<<root->data<<" ";
        printleft(root->left);
    }
    else if(root->right)
    {
        cout<<root->data<<" ";
        printleft(root->right);
    }
}

void printleaves(Node* root)
{
    if(root==NULL)
    return;
    
    printleaves(root->left);
    
    if(root->left==NULL && root->right==NULL)
    cout<<root->data<<" ";
    
    printleaves(root->right);
}

void printright(Node *root)
{
    if(root==NULL)
    return;
    
    if(root->right)
    {
        printright(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left)
    {
        printright(root->left);
        cout<<root->data<<" ";
    }
}

void printBoundary(Node *root)
{
    if(root==NULL)
    return;
    
    cout<<root->data<<" ";
    
    printleft(root->left);
    
    printleaves(root->left);
    printleaves(root->right);
    
    printright(root->right);
}
