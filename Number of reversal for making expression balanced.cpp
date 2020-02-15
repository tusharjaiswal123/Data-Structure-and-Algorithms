#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n=0,m=0,j;
	    string s;
	    cin>>s;
	    j=s.length();
	    
	    if(j%2==0)
	    {
	        stack<char> k;
	        for(int i=0;i<j;i++)
	        {
	            if(s[i]=='{')
	            {
	                k.push(s[i]);
	            }
	            else if(s[i]=='}')
	            {
	                if(k.empty())
	                m++;
	                else
	                k.pop();
	            }
	        }
	        
	        while(!k.empty())
	        {
	            n++;
	            k.pop();
	        }
	        
	        m=ceil(double(m)/2);
	        n=ceil(double(n)/2);
	        
	        cout<<m+n<<endl;
	    }
	   else
	   cout<<-1<<endl;
	   
	}
	return 0;
}
