PROBLEM:

Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.
Constraints:
1 ≤ T ≤ 110
1 ≤ N ≤ 106
-107 ≤ A[i] <= 107
Example:
Input
2
5
1 2 3 -2 5
4
-1 -2 -3 -4
Output
9
-1


SOLUTION:

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,ans;
	    cin>>n;
	    
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    int dp[n];
	    dp[0]=a[0];
	    ans=dp[0];
	    
	    for(i=1;i<n;i++)
	    {
	        dp[i]=max(dp[i-1]+a[i],a[i]);
	        ans=max(ans,dp[i]);
	    }
	    
	    cout<<ans<<endl;
	    
	}
	return 0;
}
