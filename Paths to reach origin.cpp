PROBLEM:

You are standing on a point (n, m) and you want to go to origin (0, 0) by taking steps either left or down i.e. from each point you are
allowed to move either in (n-1, m) or (n, m-1). Find the number of paths from point to origin.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two
integers n and m representing the point.
Output:
For each testcase, in a new line, print the total number of paths from point to origin.
Constraints:
1 <= T<= 100
1 <= n, m <= 25
Example:
Input:
3
3 2
3 6
3 0
Output:
10
84
1


SOLUTION:

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,m,i,j;
	    cin>>n>>m;
	    
	    int dp[n+1][m+1];
	    
	    for(i=0;i<=n;i++)
	    {
	        for(j=0;j<=m;j++)
	        {   
	            if(i==0 && j==0)
	            dp[i][j]=0;
	            
	            else if(i==0)
	            dp[i][j]=1;
	            
	            else if(j==0)
	            dp[i][j]=1;
	            
	            else
	            dp[i][j]=dp[i-1][j]+dp[i][j-1];
	        }
	    }
	    
	    cout<<dp[n][m]<<endl;
	}
	return 0;
}
