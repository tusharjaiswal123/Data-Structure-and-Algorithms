PROBLEM:

Given a string which includes characters a, b, c, ..., z. Where value of a=1, b=2, ..., z=26. Now find the largest increasing sub sequence in the string and print it's length.

Note:  Sub sequence doesn't require elements to be consecutively increasing.
Input:
The first line contains a single integer T i.e. the number of test cases. The first and the only line of each test case consists of a string S.

Output:
In one line print the length of the largest increasing sub sequence in the string.

Constraints:
1<=T<=100
1<=|Length of String|<=1000
 
Examples:
Input:
2
pcbhdbjcvhjsdjhvczvd
abcdapzfqh
Output:
7
6


SOLUTION:

#include <iostream>
#include<climits>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,j,ans=INT_MIN;
	    string s;
	    cin>>s;
	    
	    n=s.length();
	    int dp[n];
	    
	    for(i=0;i<n;i++)
	    dp[i]=1;
	    
	   
	    
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<i;j++)
	        {
	            if(s[j]<s[i])
	            dp[i]=max(dp[i],dp[j]+1);
	        }
	        ans=max(ans,dp[i]);
	    }

	    
	    cout<<ans<<endl;
	}
	return 0;
}
