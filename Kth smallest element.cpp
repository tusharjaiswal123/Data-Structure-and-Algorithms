#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);       

int main() {
    fastio;
    
	int t;
	 cin>>t;
	 
	 while(t--)
	 {
	     int n,k,i;
	     cin>>n;
	     int a[n];
	     priority_queue<int> q;
	     
	     for(i=0;i<n;i++)
	     cin>>a[i];
	     
	     cin>>k;
	     
	     for(i=0;i<n;i++)
	     {
	         if(i<k)
	         q.push(a[i]);
	         else
	         {
	             if(a[i]<q.top())
	             {
	                 q.pop();
	                 q.push(a[i]);
	             }
	         }
	     }
	     
	     cout<<q.top()<<endl;
	 }
	return 0;
}
