void bottomView(Node *root)
{
   if(root==NULL)
   return;
   
   map<int,int> m;
   int hd=0;
   
   queue<pair<Node *,int>> q;
   q.push({root,hd});
   
   while(!q.empty())
   {
       pair<Node *,int> p=q.front();
       q.pop();
       
       hd=p.second;
       Node *temp=p.first;
       
       m[hd]=temp->data;
       
       if(temp->left!=NULL)
       q.push({temp->left,hd-1});
       
       if(temp->right!=NULL)
       q.push({temp->right,hd+1});
   }
   
   for(auto it=m.begin();it!=m.end();it++)
   {
       cout<<it->second<<" ";
   }
   
}
