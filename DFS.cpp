void dfs(int s, vector<int> g[], bool vis[])
{
    
    vis[s]=true;
    cout<<s<<" ";
    
    for(int v:g[s])
    {
        if(!vis[v])
        dfs(v,g,vis);
    }

}
