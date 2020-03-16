## USING BFS

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


## USING DFS

