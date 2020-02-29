#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k,i;
        cin>>n>>k;
        
        int a[n];
        unordered_set<int> s;
        
        for(i=0;i<n;i++)
        cin>>a[i];
        
        s.insert(a[0]);
        for(i=1;i<n;i++)
        {
            if(s.find(a[i])!=s.end())
            {
                k--;
            }
            else
            s.insert(a[i]);
        }
        if(k<0)
        k=0;
        
        cout<<s.size()-k<<endl;
        
    }
	return 0;
}
