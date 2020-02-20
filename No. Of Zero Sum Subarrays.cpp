#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,s1=0,ans=0;
	    cin>>n;
	    
	    int a[n];
	    unordered_map<int,int> m;
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    m[0]++;
	    for(i=0;i<n;i++)
	    {
	        s1+=a[i];
	        
	        if(m.find(s1)!=m.end())
	        {
	            ans+=m[s1];
	        }
	        m[s1]++;
	    }
	    
	    cout<<ans<<endl;
	}
	return 0;
}
