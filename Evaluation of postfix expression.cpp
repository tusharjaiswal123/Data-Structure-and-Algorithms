#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int i,x,y,a;
	    string s;
	    cin>>s;
	    
	    stack<int> st;
	    
	    for(i=0;i<s.length();i++)
	    {
	        if(s[i]>='0' && s[i]<='9')
	        st.push(s[i]-'0');
	        else
	        {
	            y=st.top();
	            st.pop();
	            x=st.top();
	            st.pop();
	            
	            if(s[i]=='+')
	            a=x+y;
	            else if(s[i]=='-')
	            a=x-y;
	            else if(s[i]=='*')
	            a=x*y;
	            else if(s[i]=='/')
	            a=x/y;
	            
	            st.push(a);
	        }
	    }
	    cout<<st.top()<<endl;
	}
	return 0;
}
