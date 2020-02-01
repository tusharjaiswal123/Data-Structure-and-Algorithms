void bToDLL(Node *root, Node **head_ref)
{   
    if(root==NULL)
    return;
    
    static Node* prev=NULL;
    
    bToDLL(root->left,head_ref);
    
    if(*head_ref==NULL)
    {
        prev=NULL;
        *head_ref=root;
    }
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    
    bToDLL(root->right,head_ref);
    
}
