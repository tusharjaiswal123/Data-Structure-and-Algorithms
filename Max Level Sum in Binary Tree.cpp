int maxLevelSum(Node * root)
{
   queue<Node *> q;
   int s,ans=INT_MIN;
   
   q.push(root);
   
   while(!q.empty())
   {
       int size=q.size();
       s=0;
       while(size--)
       {
        Node * p=q.front();
        q.pop();
        s+=p->data;
   
        if(p->left)
        q.push(p->left);
        
        if(p->right)
        q.push(p->right);
       }
       ans=max(ans,s);
   }
   
   return ans;
}

