PROBLEM:

Given an array A of size N, the task is to find the longest subsequence such that difference between adjacents is one.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the size of array A.The second line of each test case contains N space separated integers denoting elements of the array A[ ].
Output:
For each testcase, in a new line, print the length of the longest subsequence such that difference between adjacents is one.
Constraints:
1<= T <=100
1<= N <=103
1<= A[ ] <=103
Example:
Input:
1
7
10 9 4 5 4 8 6
Output:
3

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
	    
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    int dp[n];
	    
	    for(i=0;i<n;i++)
	    {   
	        dp[i]=1;
	        for(j=0;j<i;j++)
	        {
	            if(abs(a[i]-a[j])==1)
	            dp[i]=max(dp[i],dp[j]+1);
	        }
	        ans=max(ans,dp[i]);
	    }
	    
	    cout<<ans<<endl;
	}
	return 0;
}
