void levelOrder(Node* node)
{   
    if(node==NULL)
    return;
    queue<Node *> q;
    
    q.push(node);
    
    while(!q.empty())
    {
        Node *t=q.front();
        cout<<t->data<<" ";
        q.pop();
        
        if(t->left)
        q.push(t->left);
        
        if(t->right)
        q.push(t->right);
    }
  
}
