PROBLEM:

Given two strings X and Y. The task is to find the length of the longest common substring.
Input:
First line of the input contains number of test cases T. Each test case consist of three lines, first of which contains 2 space separated integers N and M denoting the size of string X and Y strings respectively. The next two lines contains the string X and Y.
Output:
For each test case print the length of longest  common substring of the two strings .
Constraints:
1 <= T <= 200
1 <= N, M <= 100
Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC
Output:
4
1

SOLUTION:

#include <iostream>
#include<climits>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,m,i,j,ans=INT_MIN;
	    cin>>n>>m;
	    
	    string s1,s2;
	    cin>>s1>>s2;
	    
	    int dp[n+1][m+1];
	    
	    for(i=0;i<=n;i++)
	    {
	        for(j=0;j<=m;j++)
	        {
	            if(i==0 || j==0)
	            dp[i][j]=0;
	            
	            else if(s1[i-1]==s2[j-1])
	            dp[i][j]=1+dp[i-1][j-1];
	            
	            else 
	            dp[i][j]=0;
	            
	            ans=max(ans,dp[i][j]);
	        }
	    }
	    
	    cout<<ans<<endl;
	}
	return 0;
}
