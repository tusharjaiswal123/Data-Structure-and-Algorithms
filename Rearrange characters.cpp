#include <iostream>
#include<cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,flag=1,i;
	    string s;
	    cin>>s;
	    n=s.length();
	    
	    int a[26]={0};
	    
	    for(i=0;i<n;i++)
	    {
	        a[s[i]-'a']++;
	    }
	    
	    for(i=0;i<26;i++)
	    {
	        if(a[i]>ceil(double(n)/2))
	        {
	            flag=0;
	            break;
	        }
	    }
	    
	    if(flag==1)
	    cout<<1<<endl;
	    else
	    cout<<0<<endl;
	}
	return 0;
}
