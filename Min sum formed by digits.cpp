#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,a,b=0,c=0,j,k;
	    cin>>n;
	    
	    priority_queue<int,vector<int>,greater<int>> q;
	    
	    for(i=0;i<n;i++)
	    {
	        cin>>a;
            q.push(a);
	    }
	    
	    j=10;
	    k=10;
	    for(i=0;i<n;i++)
	    {
	        if(i%2==0)
	        {
	            b=b*j+q.top();
	            q.pop();
	        }
	        else
	        {
	            c=c*k+q.top();
	            q.pop();
	        }
	    }
	    
	    cout<<b+c<<endl;
	}
	return 0;
}
