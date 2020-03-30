#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int>adj[],vector<bool>& vis,int count,int s,int n)
{
    if(count==n)
    {
        return true;
    }
    
    for(auto v:adj[s])
    {
        if(!vis[v])
        {
            vis[v]=true;
            
            if(dfs(adj,vis,count+1,v,n))
            return true;
            
            vis[v]=false;
        }    
    }
    return false;
        
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int v,e,i,c,d,flag=0;
	    cin>>v>>e;
	    
	    vector<int> adj[v+1];
	    
	    for(i=0;i<e;i++)
	    {
	        cin>>c>>d;
	        adj[c].push_back(d);
	        adj[d].push_back(c);
	    }
	    
	    vector<bool> vis(v+1,false);
	    
	    
	    for(i=0;i<v;i++)
	    {   
	        if(!vis[i])
	        {
	        vis[i]=true;
	        if(dfs(adj,vis,1,i,v))
	        {
	             flag=1;
	             break;
	        }
	        vis[i]=false;
	        }
	    }
	    
	    cout<<flag<<endl;
	}
	
	return 0;
}
