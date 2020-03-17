void dfs(int i,stack<int>& s,vector<int> adj[],vector<int>& vis)
{
    vis[i]=true;
    
    for(int v:adj[i])
    {   
        if(!vis[v])
        dfs(v,s,adj,vis);
    }
    
    s.push(i);
}

int* topoSort(int V, vector<int> adj[]) {   //dependency //Only possible for DAG
    
    stack<int> s;
    vector<int> vis(V,false);
    
    for(int i=0;i<V;i++)
    {   
        if(!vis[i])
        dfs(i,s,adj,vis);
    }
    
    int *a;
    a=new int[s.size()];
    int j=0;
    
    while(!s.empty())
    {
        a[j]=s.top();
        j++;
        s.pop();
    }
    
    return a;
}


## kahns algorithm 

int* topoSort(int V, vector<int> adj[]) {
    
    vector<bool> vis(V,false);
    vector<int> indegree(V,0);
    
    int i,count=0;
    
    for(i=0;i<V;i++)
    {
        for(int v:adj[i])
        {
            indegree[v]++;
        }
    }
    
    queue<int> q;
    
    for(i=0;i<V;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    
    int *a;
    a=new int[V];
    int j=0;
    
    while(!q.empty())
    {   
        int k=q.front();
        q.pop();
        a[j]=k;
        j++;
        
        for(int v:adj[k])
        {
            indegree[v]--;
            if(indegree[v]==0)
            q.push(v);
        }
        count++;         //if count!=V  then there is cycle
        
    }
    
    return a; 
}
