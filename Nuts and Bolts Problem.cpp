#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i;
	    cin>>n;
	    
	    char s1[n],s2[n];
	    
	    for(i=0;i<n;i++)
	    cin>>s1[i];
	    
	    for(i=0;i<n;i++)
	    cin>>s2[i];
	    
	    unordered_map<char,int> m;
	    char a[9]={'!','#','$','%','&','*','@','^','~'};
	    
	    for(i=0;i<n;i++)
	    {
	        m[s1[i]]++;
	    }
	    
	    for(i=0;i<9;i++)
	    {
	        if(m[a[i]]!=0)
	        cout<<a[i]<<" ";
	    }
	    
	    cout<<endl;
	    for(i=0;i<9;i++)
	    {
	        if(m[a[i]]!=0)
	        cout<<a[i]<<" ";
	    }
	    
	    cout<<endl;
	}
	return 0;
}
