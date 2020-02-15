#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
    {   
        int ans=0;
        
        string s;
        cin>>s;
        
        stack<char> s1;
        s1.push(-1);
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
            s1.push(i);
            }
            
            else if(s[i]==')')
            {   
                s1.pop();
                
                if(!s1.empty())
                ans=max(ans,i-s1.top());
                
                else if(s1.empty())
                s1.push(i);
                
            }
        }
        cout<<ans<<endl;
    }
	
	return 0;
}
