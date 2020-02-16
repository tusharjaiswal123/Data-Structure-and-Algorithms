#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int i,k,ans=0,n;
	    int a[26]={0};
	    
	    string s;
	    cin>>s;
	    cin>>k;
	    n=s.length();
	    
	    for(i=0;i<n;i++)
	    {
	        a[s[i]-97]++;
	    }
	    
	    sort(a,a+26,greater<int>());
	    
	    i=0;
	    for(int j=0;j<k;j++)
	    {
	        a[i]--;
	        sort(a,a+26,greater<int>());
	    }
	    
	    
	    for(i=0;i<26;i++)
	    {
	        ans+=a[i]*a[i];
	    }
	    
	    cout<<ans<<endl;
	    
	    
	}
	return 0;
}


PRIORITY QUEUE Solution:

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int i,k,ans=0,n;
	    int a[26]={0};
	    
	    string s;
	    cin>>s;
	    cin>>k;
	    n=s.length();
	    priority_queue<int> q;
	    
	    for(i=0;i<n;i++)
	    {
	        a[s[i]-97]++;
	    }
	    
	    for(i=0;i<26;i++)
	    q.push(a[i]);
	    
	
	    for(int j=0;j<k;j++)
	    {
	        int k=q.top();
	        q.pop();
	        k=k-1;
	        q.push(k);
	    }
	    
	    
	    while(!q.empty())
	    {
	        int m=q.top();
	        q.pop();
	        ans+=m*m;
	    }
	    
	    cout<<ans<<endl;
	    
	    
	}
	return 0;
}
