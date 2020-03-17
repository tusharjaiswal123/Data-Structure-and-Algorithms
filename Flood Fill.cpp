#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int m,n,i,j,x,y,k;
	    cin>>n>>m;
	    
	    int a[n][m];
	    
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        cin>>a[i][j];
	    }
	    cin>>x>>y>>k;
	    
	    if(x<n && y<m)
	    {
	    queue<pair<int,int>> q;
	    q.push({x,y});
	    
	    int value=a[x][y];
	    while(!q.empty())
	    {
	        pair<int,int> p=q.front();
	        q.pop();
	        int c=p.first;
	        int d=p.second;
	        
	        a[c][d]=k;
	        
	        if(c+1<n && a[c+1][d]==value)
	        q.push({c+1,d});
	        
	        if(d+1<m && a[c][d+1]==value)
	        q.push({c,d+1});
	        
	        if(c-1>=0 && a[c-1][d]==value)
	        q.push({c-1,d});
	        
	        if(d-1>=0 && a[c][d-1]==value)
	        q.push({c,d-1});
	        
	    }
	    }
	    
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        cout<<a[i][j]<<" ";
	    }
	    cout<<endl;
	    
	}
	return 0;
}

## using recursion

#include <bits/stdc++.h>
using namespace std;

void floodfill(vector<vector<int>>& a,int x,int y,int k,int val)
{  
    if(x>=a.size() || y>=a[0].size() || x<0 || y<0)
    return;
    
    if(a[x][y]!=val)
    return;
    
    a[x][y]=k;
    
    floodfill(a,x+1,y,k,val);
    floodfill(a,x-1,y,k,val);
    floodfill(a,x,y+1,k,val);
    floodfill(a,x,y-1,k,val);
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int i,j,x,y,k,m,n;
	    cin>>n>>m;
	    
	    vector<vector<int>> a(n,vector<int>(m,0));
	    
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        cin>>a[i][j];
	    }
	    cin>>x>>y>>k;
	    
	    if(x<n && y<m)
	    {
	        int val=a[x][y];
	        floodfill(a,x,y,k,val);
	    }
	    
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        cout<<a[i][j]<<" ";
	    }
	    cout<<endl;
	    
	}
	return 0;
}

