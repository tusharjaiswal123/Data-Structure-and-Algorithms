#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,i,a,k,l,m;
	cin>>n;
	
	priority_queue<int,vector<int>,greater<int>> qmin;
	priority_queue<int> qmax;
	
	cin>>a;
	qmax.push(a);
	cout<<a<<endl;
	m=a;
	for(i=1;i<n;i++)
	{   
	    cin>>a;
	    if(a<qmax.top())
	    qmax.push(a);
	    else
	    qmin.push(a);
	    
	    k=qmax.size();
	    l=qmin.size();
	    if(abs(k-l)==2)
	    {
	        if(k>l)
	        {
	            qmin.push(qmax.top());
	            qmax.pop();
	        }
	        else
	        {
	            qmax.push(qmin.top());
	            qmin.pop();
	        }
	        k=qmax.size();
	        l=qmin.size();
	    }
	    if(abs(k-l)==1)
	    {
	        if(k>l)
	        cout<<qmax.top()<<endl;
	        else
	        cout<<qmin.top()<<endl;
	    }
	    
	    else if(k==l)
	    {
	        cout<<(qmax.top()+qmin.top())/2<<endl;
	    }
	    
	}
	
	
	return 0;
}
