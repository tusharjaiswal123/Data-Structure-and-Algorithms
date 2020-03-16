## USING DFS

bool dfs(vector<int> adj[],vector<bool>& vis,vector<bool> ancestor,int s)
{
    vis[s]=true;
    ancestor[s]=true;
    
    for(int v:adj[s])
    {
        if(!vis[v])
        {
            if(dfs(adj,vis,ancestor,v))
            return true;
        }
        
        else if(vis[v] && ancestor[v]==true)
        return true;
    }
    
    ancestor[s]=false;
    return false;
}

bool isCyclic(int V,vector<int> adj[])
{
    vector<bool> vis(V,false);
    vector<bool> ancestor(V,false);
    
    for(int i=0;i<V;i++)
    {   
        if(!vis[i])
        {
        if(dfs(adj,vis,ancestor,i))
        return true;
        }
    }
    
    return false;
}
