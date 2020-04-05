PROBLEM:

Given two strings str1 and str2, find the length of the smallest string which has both, str1 and str2 as its sub-sequences.
Note: str1 and str2 can have both uppercase and lowercase letters.
Input:
The first line of input contains an integer T denoting the number of test cases.Each test case contains two space separated strings.
Output:
For each testcase, in a new line, output the length of the required string.
Constraints:
1 <= T <= 100
1<= |str1|, |str2| <= 100
Example:
Input:
2
abcd xycd
efgh jghi
Output:
6
6


SOLUTION:

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n1,n2,i,j;
	    string s1,s2;
	    cin>>s1>>s2;
	    
	    n1=s1.length();
	    n2=s2.length();
	    
	    int dp[n1+1][n2+1];
	    
	    for(i=0;i<=n1;i++)
	    {
	        for(j=0;j<=n2;j++)
	        {
	            if(i==0 || j==0)
	            dp[i][j]=0;
	            
	            else if(s1[i-1]==s2[j-1])
	            dp[i][j]=1+dp[i-1][j-1];
	            
	            else
	            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    
	    cout<<n1+n2-dp[n1][n2]<<endl;
	    
	}
	return 0;
}
