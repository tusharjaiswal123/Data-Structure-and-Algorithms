#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int V,e,i,j,x,y,w,flag=1;
	    cin>>V>>e;
	    
	    vector<pair<int,int>> adj[V];
	    
	    for(i=0;i<e;i++)
	    {
	        cin>>x>>y>>w;
                    
	        adj[x].push_back({y,w});
	    }
	    
	    
	    int dist[V];
	    dist[0]=0;
	    
	    for(i=1;i<V;i++)
	    dist[i]=INT_MAX;
	    
	    for(i=0;i<V-1;i++)              //Single source shortest path algorithm
	    {   
	        for(j=0;j<V;j++)
	        {
	        for(auto k:adj[j])
            {   
                int u=j;
                int v=k.first;
                int w=k.second;
	            if(dist[u]!=INT_MAX && dist[u] + w < dist[v])
	            {
	                dist[v]=dist[u]+w;
	            }
	        }
	        }
	    }
	    
	    
	        for(j=0;j<V;j++)            //Detecting Negative Weight Cycle
	        {
	        for(auto k:adj[j])
            {   
                int u=j;
                int v=k.first;
                int w=k.second;
	            if(dist[u]!=INT_MAX && dist[u] + w < dist[v])
	            {   
	                flag=0;
	                break;
	            }
	        }
	        }
	        
	    
	    if(flag==0)
	    cout<<"1"<<endl;
	    else
	    cout<<"0"<<endl;
	}
	return 0;                          //Worst case time complexity O(n3)   n=no. of vertex
}                                    //Bedt case time complexity  O(n2)   


If Graph is DAG then we can reduce time complexity 
1.Obtain topological Sort of the DAG using dfs and store it in array
2.Now apply only one pass of Bellman Ford by vertex order obtained in step 1

