#include <bits/stdc++.h>
using namespace std;
const int N=10005;

int par[N];
int r[N];

int find(int i)
{
    if(par[i]==-1)
    {
        return i;
    }

    return par[i]=find(par[i]);
}

void merge(int s1,int s2)
{
    int p1=find(s1);
    int p2=find(s2);

    if(p1!=p2)
    {
        if(r[p1]>r[p2])
        {
            par[p2]=p1;
            r[p1]+=r[p2];
        }
        else
        {
            par[p1]=p2;
            r[p2]+=r[p1];
        }
    }
}

int main() {
    
    int n,e,i,u,v,w,ans=0;
    cin>>n>>e;

    vector< pair< int, pair <int,int> > > a;

    for(i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        a.push_back({{w},{u,v}});
    }

    sort(a.begin(),a.end());
    
    for(i=0;i<n;i++)
    {
        par[i]=-1;
        r[i]=1;
    }

    for(i=0;i<e;i++)
    {
        w=a[i].first;
        u=a[i].second.first;
        v=a[i].second.second;

        if(find(u)!=find(v))
        {
            merge(u,v);
            ans+=w;
        }
    }

    cout<<ans<<endl;


    return 0;
}
