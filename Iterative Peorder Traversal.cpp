
void preorder(Node *root)
{
    stack<Node *> s;
    s.push(root);
    
    while(!s.empty())
    {
        Node *t=s.top();
        s.pop();
        
        cout<<s->data<<" ";
        
        if(t->right)
        s.push(t->right);
        
        if(t->left)
        s.push(t->left);
    }
}
