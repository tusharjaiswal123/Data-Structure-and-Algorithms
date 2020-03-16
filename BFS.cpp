void bfs(int s,vector<int> adj[], bool vis[])
{
    queue<int> q;
    q.push(0);  // q.push(s);  s is source
    vis[0]=true;  // vis[s]=true;
    
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        
        for(int v:adj[u])
        {
            if(vis[v]==false)
            {
                q.push(v);
                vis[v]=true;
            }
        }
        
    }
    
}
