#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
	cin>>t;
	
	while(t--)
	{
	    long long int n,i,ans=INT_MIN,ar=0,k;
	    cin>>n;
	    
	    long long int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	     
	    stack<long long int> s;
	    
	    i=0;
	    
	    while(i<n)
	    {
	        if(s.empty() || a[i]>a[s.top()])
	        {
	            s.push(i);
	            i++;
	        }
	        else
	        {
	            k=s.top();
	            s.pop();
	            
	            if(s.empty())
	            ar=a[k]*i;
	            
	            else
	            ar=a[k]*(i-s.top()-1);
	            
	            ans=max(ans,ar);
	            
	        }
	    }
	    
	    while(!s.empty())
	    {
	        k=s.top();
	        s.pop();
	        if(s.empty())
	        {
	           ar=a[k]*i;
	        }
	        else
	        {
	            ar=a[k]*(i-s.top()-1);
	        }
	        ans=max(ans,ar);
	    }
	    
	    cout<<ans<<endl;
	}
	
	return 0;
}
