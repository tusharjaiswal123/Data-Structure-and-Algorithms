void rightView(Node *root)
{
   if(root==NULL)
   return;
   
   map<int,int> m;
   int vd=0;
   
   queue<pair<Node *,int>> q;
   q.push({root,vd});
   
   while(!q.empty())
   {
       pair<Node *,int> p=q.front();
       q.pop();
       
       vd=p.second;
       Node *temp=p.first;
       
       m[vd]=temp->data;
       
       if(temp->left)
       q.push({temp->left,vd+1});
       
       if(temp->right)
       q.push({temp->right,vd+1});
   }
   
   for(auto it=m.begin();it!=m.end();it++)
   cout<<it->second<<" ";
   
}
