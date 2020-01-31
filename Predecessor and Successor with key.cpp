void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==NULL)
    return;
    
    if(root->key==key)
    {
        if(root->right!=NULL)
        {
            Node *temp=root->right;
            
            while(temp->left!=NULL)
            temp=temp->left;
            
            suc=temp;
        }
        
        if(root->left!=NULL)
        {
            Node *t=root->left;
            while(t->right!=NULL)
            t=t->right;
            
            pre=t;
        }
        return;
    }
    
    if(root->key<key)
    {
        pre=root;
        findPreSuc(root->right,pre,suc,key);
    }
    else if(root->key>key)
    {
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
   

}
