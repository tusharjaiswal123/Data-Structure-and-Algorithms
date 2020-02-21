1.Using map and queue

void verticalOrder(Node *root)
{
    if(root==NULL)
    return;
    
    map<int,vector<int>> m;
    int hd=0;
    
    queue<pair<Node *,int>> q;
    q.push(make_pair(root,hd));
    
    
    while(!q.empty())
    {
        pair<Node *,int> p=q.front();
        q.pop();
        
        hd=p.second;
        Node *temp=p.first;
        
        m[hd].push_back(temp->data);
        
        if(temp->left!=NULL)
        q.push(make_pair(temp->left,hd-1));
        
        if(temp->right!=NULL)
        q.push(make_pair(temp->right,hd+1));
    }
    
    for(auto it=m.begin();it!=m.end();it++)
    {
        for(int i=0; i < (it->second.size()) ; i++)
        cout<<it->second[i]<<" ";

    }
    
}

2.Using multimap

