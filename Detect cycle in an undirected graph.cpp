1.USING BFS

bool isCyclicConn(vector<int> adj[],int s,int V,vector<bool>& vis)
{
    vector<int> parent(V,-1);
    
    queue<int> q;
    
    q.push(s);
    vis[s]=true;
    
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        
        for(auto v:adj[u])
        {
            if(!vis[v])
            {
                vis[v]=true;
                q.push(v);
                parent[v]=u;
            }
            else if(parent[u]!=v)
            return true;
        }
    }
    
    return false;
}
bool isCyclic(vector<int> adj[], int V)
{   
   vector<bool> vis(V,false);
   for(int i=0;i<V;i++)
   {
       if(!vis[i]&&isCyclicConn(adj,i,V,vis))
       return true;
   }
   return false;
}


2.USING DFS

bool isCyclicConn(vector<int> adj[],vector<bool>& vis,int s,int parent)
{
    vis[s]=true;
    
    for(auto v:adj[s])
    {
        if(!vis[v])
        {   
            if(isCyclicConn(adj,vis,v,s))
            return true;
        }
        
        else if(vis[v]==true && v!=parent)
        return true;
    }
    
    return false;
}

bool isCyclic(vector<int> adj[],int V)
{
    vector<bool> vis(V,false);
    
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(isCyclicConn(adj,vis,i,-1))
            return true;
        }
    }
    return false;
}
