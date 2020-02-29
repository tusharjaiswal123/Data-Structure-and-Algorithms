#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,k,i,a;
	    cin>>n>>k;
	  
	    priority_queue<int,vector<int>,greater<int>> q;
	    
	    for(i=0;i<n;i++)
	    {
	        cin>>a;
	        
	        if(i<k)
	        q.push(a);
	        else
	        {
	            if(q.top()<a)
	            {
	                q.pop();
	                q.push(a);
	            }
	        }
	    }
	    
	    vector<int> v;
	    while(!q.empty())
	    {
	        v.emplace_back(q.top());
	        q.pop();
	    }
	    
	    
	    for(int i=v.size()-1;i>=0;i--)
	    cout<<v[i]<<" ";
	    
	    cout<<endl;
	}
	return 0;
}
