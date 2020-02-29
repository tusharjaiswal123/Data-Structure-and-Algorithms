#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        long long n,i,a,ans=0,b,c;
        cin>>n;
        
        priority_queue<long long,vector<long long>,greater<long long>> q;
        
        for(i=0;i<n;i++)
        {
            cin>>a;
            q.push(a);
        }
        
        while(q.size()!=1)
        {
            b=q.top();
            q.pop();
            c=q.top();
            q.pop();
            q.push(b+c);
            ans+=b+c;
        }
        
        cout<<ans<<endl;
    }
	return 0;
}
