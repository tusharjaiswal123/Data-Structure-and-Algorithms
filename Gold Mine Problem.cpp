PROBLEM:

Given a gold mine (M) of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\) that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Your task is to find out maximum amount of gold which he can collect.
Examples:
Input : M[][] = {{1, 3, 3},
                 {2, 1, 4},
                 {0, 6, 4}};
Output : 12 
{(1,0)->(2,1)->(2,2)}

Input: M[][] = {{1, 3, 1, 5},
                {2, 2, 4, 1},
                {5, 0, 2, 3},
                {0, 6, 1, 2}};
Output : 16
(2,0) -> (1,1) -> (1,2) -> (0,3) OR
(2,0) -> (3,1) -> (2,2) -> (2,3)


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer n and m denoting the size of the matrix. Then in the next line are n*m space separated values of the matrix.

Output:
For each test case in a new line print an integer denoting the max gold the miner could collect.

Constraints:
1<=T<=100
1<=n,m<=20
1<=M[][]<=100

Example:
Input:
2
3 3 
1 3 3 2 1 4 0 6 4
2 2
1 2 3 4
Output:
12
7


SOLUTION:

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,m,i,j,ans=-1,x,y,z;
	    cin>>n>>m;
	    
	    int a[n][m];
	    int dp[n][m];
	    
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        {
	            cin>>a[i][j];
	            dp[i][j]=a[i][j];
	        }     
	    }
	  
	    
	    for(j=1;j<m;j++)
	    {
	        for(i=0;i<n;i++)
	        {   
	            x=0;
	            y=0;
	            z=0;
	            if(i-1>=0)
	            x=dp[i-1][j-1];
	            
	            if(i+1<n)
	            y=dp[i+1][j-1];
	            
	            z=dp[i][j-1];
	            
	            dp[i][j]+=max({x,y,z});
	            
	        }
	    }
	    
	   
	    
	    for(i=0;i<n;i++)
	    {
	        ans=max(ans,dp[i][m-1]);
	    }
	    
	    cout<<ans<<endl;
	}
	return 0;
}
