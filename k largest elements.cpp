#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,k,i,a;
	    cin>>n>>k;
	    
	    int a[n];
	    priority_queue<int> q;
	    
	    for(i=0;i<n;i++)
	    {
	        cin>>a;
	        q.push(a);
	    }
	    
	    for(i=0;i<k;i++)
	    {
	        cout<<q.top()<<" ";
	        q.pop();
	    }
	    cout<<endl;
	}
	return 0;
}
