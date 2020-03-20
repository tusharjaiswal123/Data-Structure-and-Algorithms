void dfs1(vector<int> adj[],vector<bool>& vis,stack<int>& s,int src)
{
    vis[src]=true;
    
    for(auto k:adj[src])
    {
        if(!vis[k])
        {
            dfs1(adj,vis,s,k);
        }
    }
    s.push(src);
}

void dfs2(vector<int> rev[],vector<bool>& vis,int src)
{
    vis[src]=true;
    
    for(auto k:rev[src])
    {
        if(!vis[k])
        {
            dfs2(rev,vis,k);
        }
    }
}

int kosaraju(int V, vector<int> adj[])
{
    vector<bool>vis(V,false);
    int i,ans=0;
    
    stack<int> s;
    
    for(i=0;i<V;i++)
    {
        if(!vis[i])
        {
            dfs1(adj,vis,s,i);
        }
    }
    
    vector<int> rev[V];
    for(i=0;i<V;i++)
    {
        for(auto k:adj[i])
        {
            rev[k].push_back(i);
        }
    }
    
    for(i=0;i<V;i++)
    vis[i]=false;
    
    while(!s.empty())
    {
        int m=s.top();
        s.pop();
        
        if(!vis[m])
        {
            dfs2(rev,vis,m);
            ans++;
        }
        
    }
    
    return ans;
}
