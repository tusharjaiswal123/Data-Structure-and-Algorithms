#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i;
	    cin>>n;
	    
	    unordered_map<string,int> m;
	    string s;
	    vector<int>k;
	    
	    for(i=0;i<n;i++)
	    {
	        cin>>s;
	        sort(s.begin(),s.end());
	        m[s]++;
	    }
	    
	    for(auto it=m.begin();it!=m.end();it++)
	    {
	        k.emplace_back(it->second);
	    }
	    
	    sort(k.begin(),k.end());
	    
	    for(auto it1=k.begin();it1!=k.end();it1++)
	    {
	        cout<<*it1<<" ";
	    }
	    
	    cout<<endl;
	}
	return 0;
}
