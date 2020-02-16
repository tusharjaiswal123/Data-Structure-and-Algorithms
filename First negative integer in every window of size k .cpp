#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,k,flag;
	    cin>>n;
	    
	    queue<int> q;
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    
	    cin>>k;
	    
	    for(i=0;i<n-k+1;i++)
	    {   
	        flag=0;
	        for(int j=0;j<k;j++)
	        {
	            q.push(a[i+j]);
	            if(a[i+j]<0 && flag==0)
	            {
	                cout<<q.front()<<" ";
	                flag=1;
	            }
	            q.pop();
	            
	        }
	        if(flag==0)
	        cout<<0<<" ";
	    }
	    cout<<endl;
	    
	    
	}
	return 0;
}
