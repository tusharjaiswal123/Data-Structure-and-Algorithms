PROBLEM:

Given 3 strings X, Y and Z, the task is to find the longest common sub-sequence in all three given sequences.
 
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains integers n, m and k denoting the length of strings X, Y and Z respectively.
The second line of each test case contains the three strings X, Y and Z. The string consists of only lower case english alphabets.

Output:
Print the length of the longest common sub- sequence of the three strings for each test case in a new line.

Constraints:
1<= T <=100
1<= N, M, K <=100

Example:
Input:
1
5 8 13
geeks geeksfor geeksforgeeks


SOLUTION:

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n1,n2,n3,i,j,k;
	    cin>>n1>>n2>>n3;
	    
	    string s1,s2,s3;
	    cin>>s1>>s2>>s3;
	    
	    
	    int dp[n1+2][n2+1][n3+1];
	    
	    for(i=0;i<=n1;i++)
	    {
	        for(j=0;j<=n2;j++)
	        {
	            for(k=0;k<=n3;k++)
	            {
	                if(i==0 || j==0 || k==0)
	                dp[i][j][k]=0;
	                
	                else if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])
	                dp[i][j][k]=dp[i-1][j-1][k-1]+1;
	                
	                else
	                dp[i][j][k]=max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
	            }
	        }
	    }
	    
	    cout<<dp[n1][n2][n3]<<endl;
	}
	return 0;
}
