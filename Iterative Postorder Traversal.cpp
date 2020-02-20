
void postorder(Node *root)
{
    stack<Node *> s1,s2;
    s1.push(root);
    
    while(!s1.empty())
    {   
        Node *t=s1.top();
        s1.pop();
        s2.push(t);
        
        if(t->right)
        s1.push(t->right);
        
        if(t->left)
        s1.push(t->left);
    }
    
    while(!s2.empty())
    {
        Node *w=s2.top();
        s2.pop();
        cout<<w->data<<" ";
    }
}
