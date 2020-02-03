#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main() {
    ios;
	long long t;
	cin>>t;
	
	while(t--)
	{
	    long long n,i;
	    cin>>n;
	    unordered_map<long long,long long> m;
	    stack<long long> s;
	    
	    long long a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    s.push(a[0]);
	    for(i=1;i<n;i++)
	    {   
	   
	           while(!s.empty() && (s.top()<a[i]) )
	           {
	               m[s.top()]=a[i];
	               s.pop();
	           }
	           s.push(a[i]);
	    }
	    
	    while(!s.empty())
	    {
	        m[s.top()]=-1;
	        s.pop();
	    }
	    
	    
	    for(i=0;i<n;i++)
	    cout<<m[a[i]]<<" ";
	    
	    cout<<endl;
	    
	}
	return 0;
}
