PROBLEM:

Given a String, find the longest palindromic subsequence

Input:
The first line of input contains an integer T, denoting no of test cases. The only line of each test case consists of a string S(only lowercase)

Output:
Print the Maximum length possible for palindromic subsequence.

Constraints:
1<=T<=100
1<=|Length of String|<=1000
 
Examples:
Input:
2
bbabcbcab
abbaab
Output:
7
4


SOLUTION:

#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,j;
	    string s1,s2;
	    cin>>s1;
	    
	    n=s1.length();
	    s2=s1;
	    reverse(s2.begin(),s2.end());   //Reverse string and apply LCS
	    
	    int dp[n+1][n+1];
	    
	    for(i=0;i<=n;i++)
	    {
	        for(j=0;j<=n;j++)
	        {
	            if(i==0 || j==0)
	            dp[i][j]=0;
	            
	            else if(s1[i-1]==s2[j-1])
	            dp[i][j]=1+dp[i-1][j-1];
	            
	            else 
	            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
	        }
	    }
	    
	    cout<<dp[n][n]<<endl;
	    
	}
	return 0;
}
