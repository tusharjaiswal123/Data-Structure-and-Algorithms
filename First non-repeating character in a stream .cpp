#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i;
	    cin>>n;
	    
	    char a[n];
	    queue<char> q;
	    
	    int freq[26]={0};
	    
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    
	    for(i=0;i<n;i++)
	    {
	        freq[a[i]-'a']++;
	        q.push(a[i]);
	        
	        while(!q.empty())
	        {
	            if(freq[q.front()-'a']>1)
	            q.pop();
	            
	            else
	            {
	                cout<<q.front()<<" ";
	                break;
	            }
	        }
	        if(q.empty())
	        cout<<-1<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
