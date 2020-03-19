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

int main()
{
    //call bfs for all unvisited vetex in case if graph is disconnected
}


## Iterative DFS

void itrdfs(vector<int> adj[],vector<int>& vis,int src)
{
     stack<int> s;
     s.push(src);
    
    while(!s.empty())
    {
        int k=s.top();
        s.pop();
        
        if(vis[k])
            continue;
        
        vis[k]=true;
        cout<<k<<" ";
        
        for(auto j:adj[k])
        {   
            if(!vis[j]
               s.push(j);
        }
    }
}

int main()
{
    vector<int> adj[V];
    vector<int> vis(V,false);
    
    for(i=0;i<V;i++)
    {
        itrdfs(adj,vis,i)
    }
    
    return 0;
}
