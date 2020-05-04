PROBLEM:

Given a N X N  matrix Matrix[N][N] of positive integers.  There are only three possible moves from a cell Matrix[r][c].
1. Matrix[r+1][c]
2. Matrix[r+1][c-1]
3. Matrix[r+1][c+1]
Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.
Input:
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the order of matrix. Next line contains N*N integers denoting the
elements of the matrix in row-major form.

Output:
Output the largest sum of any of the paths starting from any cell of row 0 to any cell of row N-1. Print the output of each test case in
a new line.

Constraints:
1<=T<=20
2<=N<=20
1<=Matrix[i][j]<=1000 (for all 1<=i<=N && 1<=j<=N)

Example:
Input:
1
2
348 391 618 193 
Output:
1009


SOLUTION:

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,j,ans=INT_MIN;
	    cin>>n;
	    
	    int a[n][n];
	    
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        cin>>a[i][j];
	    }
	    
	    int dp[n][n];
	    
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            dp[i][j]=a[i][j];
	            
	            if(i!=0)
	            {
	                if(j==0 && j+1<n)
	                dp[i][j]+=max(dp[i-1][j],dp[i-1][j+1]);
	            
	                else if(j==n-1 && j-1>=0)
	                dp[i][j]+=max(dp[i-1][j],dp[i-1][j-1]);
	            
	                else if(j-1>=0 && j+1<n)
	                dp[i][j]+=max({dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]});
	            }
	        }
	    }
	    
	    for(j=0;j<n;j++)
	    ans=max(ans,dp[n-1][j]);
	    
	    cout<<ans<<endl;
	}
	return 0;
}
