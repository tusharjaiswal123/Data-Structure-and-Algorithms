PROBLEM:

Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break.
You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best
strategy.There are few rules given below. 
An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page
Input:
The first line of input is  T denoting the number of testcases.Then each of the T lines contains two positive integer N and K where
'N' is the number of eggs and 'K' is number of floor in building.
Output:
For each test case, print a single line containing one integer the minimum number of attempt you need in order find the critical floor.
Constraints:
1<=T<=30
1<=N<=10
1<=K<=50
Example:
Input:
2
2 10
3 5
Output:
4
3

SOLUTION:


#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,k,i,j,u,ans=INT_MAX;
	    cin>>n>>k;
	    
	    int dp[n+1][k+1];
	    
	    for(i=0;i<=n;i++)
	    {
	        dp[i][0]=0;       //for 0 floor we need 0 trials
	        dp[i][1]=1;       // for 1 floor we need 1 trial
	    }
	    
	    for(j=0;j<=k;j++)
	    dp[1][j]=j;           //if we have one egg then trial will be equal
	                          //to number of floors
	    for(i=2;i<=n;i++)
	    {   
	        for(j=2;j<=k;j++)
	        {   
	            dp[i][j]=INT_MAX;
	            for(u=1;u<=j;u++)
	            {
	                dp[i][j]=min(dp[i][j],1 + max(dp[i-1][u-1],dp[i][j-u]) );
	            }
	        }
	    }
	    
	    cout<<dp[n][k]<<endl;
	}
	return 0;
}
