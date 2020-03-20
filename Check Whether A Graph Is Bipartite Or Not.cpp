There are two algorithm
1.2-Coloring
2.Odd cycle

1.2-Coloring

bool dfs(int G[][MAX],int V,vector<bool>& vis,int color[],int src)
{
    for(int k=0;k<V;k++)
    {
        if(G[src][k]==1)
        {
            if(!vis[k])
            {
            vis[k]=true;
            
            if(color[src]==1)
            color[k]=0;
            else
            color[k]=1;
            
            if(dfs(G,V,vis,color,k)==false)
            return false;
            }
            else if(color[k]==color[src])
            {
            return false;
            }
        }
    }
    return true;
}
bool isBipartite(int G[][MAX],int V)
{
    int i;
    vector<bool>vis(V,false);
    int color[V];
    
    for(i=0;i<V;i++)
    {   
        if(!vis[i])
        {   
            vis[i]=true;
            color[i]=0;
            if(dfs(G,V,vis,color,i)==false)
            {
                return false;
            }
        }
    }
    return true;
    
}

2.odd cycle

bool bfs(int G[][MAX],int V,vector<bool>& vis,int level[],int src)
{
    queue<int> q;
    q.push(src);
    vis[src]=true;
    level[src]=0;
    
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        
        for(int m=0;m<V;m++)
        {
            if(G[k][m]==1)
            {
                if(!vis[m])
                {   
                    vis[m]=true;
                    level[m]=level[k]+1;
                    q.push(m);
                }
                else if(level[k]==level[m])
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int G[][MAX],int V)
{
    int i;
    vector<bool>vis(V,false);
    int level[V];
    
    for(i=0;i<V;i++)
    {   
        if(!vis[i])
        {   
            if(bfs(G,V,vis,level,i)==false)
            {
                return false;
            }
        }
    }
    return true;
    
}
