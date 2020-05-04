PROBLEM:

Given a string S, we need to write a program to check if it is possible to construct the given string S by performing any of the
below operations any number of times. In each step, we can:
Add any character at the end of the string.
or, append the string to the string itself.
The above steps can be applied any number of times. We need to print the minimum steps required to form the string.
Input:
The first line contains an integer T, the number of test cases. For each test case, there is a string s which we need to form. 
Output:
For each test case, the output is an integer displaying the minimum number of steps required to form that string.
Constraints:
1<=T<=100
1<=s.length()<=10^5
Example:
Input
3
aaaaaaaa 
aaaaaa 
abcabca
Output
4
4
5


SOLUTION:

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i;
	    string s;
	    cin>>s;
	    
	    n=s.length();
	    
	    int dp[n+1];
	    dp[0]=0;
	    dp[1]=1;
	    
	    for(i=2;i<=n;i++)
	    {
	        if(i%2==1)
	        dp[i]=1+dp[i-1];
	        else
	        {
	            if(s.substr(0,i/2)==s.substr(i/2,i/2))
	            dp[i]=1+dp[i/2];
	            else
	            dp[i]=1+dp[i-1];
	        }
	    }
	    
	    cout<<dp[n]<<endl;
	}
	return 0;
}

