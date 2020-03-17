string printOrder(string dict[], int N, int k) {
    
    vector<int> adj[k];
    int i,j;
    
    for(i=0;i<N-1;i++)
    {
        string s1=dict[i];
        string s2=dict[i+1];
        
        for(j=0;j<min(s1.length(),s2.length());j++)
        {
            if(s1[j]!=s2[j])
            {
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
    
    
    vector<int> indegree(k,0);
    
    
    for(i=0;i<k;i++)
    {
        for(int v:adj[i])
        {
            indegree[v]++;
        }
    }
    
    queue<int> q;
    string ans;
    ans="";
    
    for(i=0;i<k;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        
        ans+=(char)(u+'a');
        
        for(int v:adj[u])
        {
            indegree[v]--;
            if(indegree[v]==0)
            q.push(v);
        }
        
    }
    
    return ans;
}
