PROBLEM:
You are given a weighted undirected graph. The vertices are enumerated from 1 to n. Your task is to find the shortest path between the vertex 1 and the vertex n.
Input
The first line contains two integers n and m (2 ≤ n ≤ 105, 0 ≤ m ≤ 105), where n is the number of vertices and m is the number of edges. Following m lines contain one edge
each in form ai, bi and wi (1 ≤ ai, bi ≤ n, 1 ≤ wi ≤ 106), where ai, bi are edge endpoints and wi is the length of the edge.
It is possible that the graph has loops and multiple edges between pair of vertices.
Output
Write the only integer -1 in case of no path. Write the shortest path in opposite case. If there are many solutions, print any of them.


SOLUTION:

#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define abs(x) (x<0?(-x):x)
#define fr(i,k) for(i=0;i<k;i++)
#define f(i,k) for(i=1;i<=k;i++)
#define clr(a,x) memset(a,x,sizeof(a))
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define ALL(c) (c).begin(),(c).end()
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define em emplace_back
#define ulli unsigned long long int
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    fastio;

    ulli n,m,i,u,v,w,o;
    cin>>n>>m;

    vector<pair<ulli,ulli>> adj[n+1];    //Create Graph
    ulli dist[n+1];                      //Store distance of all vertex from source vertex
    ulli help[n+1];                      //to get shortest path


    for(i=0;i<=n;i++)
    {
        dist[i]=INF;
        help[i]=-1;
    }


    for(i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }


    set<pair<ulli,ulli>> s;                    //store distance of each vertex with vertex number in sorted order

    s.insert({0,1});  // o for distance and 1 for source node
    dist[1]=0;

    while(!s.empty())
    {
        auto k=s.begin();                      //it will contain vertex with lowest distance 
        ulli u=k->second;
        ulli w=k->first;
        s.erase(s.begin());

        for(auto l:adj[u])
        {
            if(dist[l.first]>w+l.second)
            {
                s.erase({dist[l.first],l.first});
                dist[l.first]=w+l.second;
                help[l.first]=u;
                s.insert({dist[l.first],l.first});
            }
        }
    }

    if(help[n]==-1)
        cout<<-1<<endl;
    else
    {
            stack<ulli> st;
            o=n;
            st.push(n);
            while(1)
            {   o=help[o];
                st.push(o);
                if(o==1)
                    break;
            }

            while(!st.empty())
            {
                cout<<st.top()<<" ";
                st.pop();
            }

            cout<<endl;
    }


    return 0;                 //Time complexity O((v+e)logv)
}





Implementation of Dijikstra's Algorithm using Priority queue:
    
    

#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main() {

	int t;
	cin>>t;

	while(t--)
	{
		int n,m,i,x,y,u,s;
		cin>>n>>m;

		vector<pair<int,int>> adj[n+1];
		vector<int> dis(n+1,inf);
		priority_queue< pair<int,int> ,vector< pair<int,int> >,greater< pair<int,int> > > pq;

		for(i=0;i<m;i++)
		{
			cin>>x>>y>>u;
			adj[x].push_back({y,u});
			adj[y].push_back({x,u});
		}

		cin>>s;
		dis[s]=0;

		pq.push({0,s});

		while(!pq.empty())
		{
			auto p=pq.top();
			pq.pop();

			for(auto k:adj[p.second])
			{
				if(dis[k.first]>dis[p.second]+k.second)
				{
					dis[k.first]=dis[p.second]+k.second;
					pq.push({dis[k.first],k.first});
				}
			}
		}

		for(i=1;i<=n;i++)
		{
			if(dis[i]==inf)
			dis[i]=-1;

			if(i==s)
			continue;

			else
			cout<<dis[i]<<" ";
		}

		cout<<endl;
	}
	return 0;
}
