Node * findmin(Node* temp)
{
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    
    return temp;
}
Node * inOrderSuccessor(Node *root, Node *x)
{   
    if(x->right!=NULL)
    {
        return findmin(x->right);
    }
    else
    {
        Node *s=NULL;
        
        while(root!=NULL)
        {
            if(x->data<root->data)
            {
                s=root;
                root=root->left;
            }
            else if(x->data>root->data)
            root=root->right;
            else
            break;
        }
        
        return s;
    }
    
}
