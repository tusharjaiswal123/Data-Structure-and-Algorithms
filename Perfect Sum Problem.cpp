PROBLEM:

Given an array of integers and a sum, the task is to count all subsets of given array with sum equal to given sum.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains
an nteger n denoting the size of the array. The next line contains n space separated integers forming the array. The last line contains
the sum.
Output:
Count all the subsets of given array with sum equal to given sum.
Constraints:
1<=T<=10^5
1<=n<=10^5
1<=a[i]<=10^5
1<=sum<=10^5
Example:
Input:
2
6
2 3 5 6 8 10
10
5
1 2 3 4 5
10
Output:
3
3


SOLUTION:

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,sum,s=0,i,j;
	    cin>>n;
	    
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];

	    cin>>sum;
	    
	    for(i=0;i<n;i++)
	    s+=a[i];
	    
	    vector<vector<int>> dp(n+1,vector<int>(s+1,0));
	    
	    for(j=1;j<=s;j++)
	    dp[0][j]=0;
	    
	    for(i=0;i<=n;i++)
	    dp[i][0]=1;
	    
	    for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=s;j++)
	        {
	            if(a[i-1]>j)
	            dp[i][j]=dp[i-1][j];
	            
	            else
	            dp[i][j]=dp[i-1][j] + dp[i-1][j-a[i-1]];
	        }
	    }
	    
	    if(sum<=s)
	    cout<<dp[n][sum]<<endl;
	    else
	    cout<<0<<endl;
	}
	return 0;
}

