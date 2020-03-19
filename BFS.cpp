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


## Recursive BFS

int main()
{   
    vector<int> vis(V,false);
    queue<int> q;
    q.push(0);  // q.push(s);  s is source
    vis[0]=true;  // vis[s]=true;
    
    for(i=0;i<v;i++)     //for all unconnected components of graph
    {   
        if(!vis[i])
        bfs(adj,vis,q);
    }    
}

void bfs(vector<int> adj[], vector<int>& vis,queue<int>& q)
{
    if(q.empty())
        return;

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
    
    bfs(adj,vis,q);
}

