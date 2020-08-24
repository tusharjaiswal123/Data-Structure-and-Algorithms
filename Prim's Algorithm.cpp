#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n,e,i,u,v,w,ans=0;
    cin>>n>>e;

    vector<pair<int,int>> adj[n];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    vector<bool> vis(n,false);

    for(i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    q.push({0,0});

    while(!q.empty())
    {
        int w=q.top().first;
        int u=q.top().second;
        q.pop();

        if(vis[u])
        continue;

        ans+=w;
        vis[u]=true;

        for(auto k:adj[u])
        {
            if(!vis[k.first])
            {
                q.push({k.second,k.first});
            }
        }
    }

    cout<<ans<<endl;


    return 0;
}
