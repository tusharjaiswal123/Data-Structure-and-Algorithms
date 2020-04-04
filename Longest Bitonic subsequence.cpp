PROBLEM:

Given an array of positive integers. The task is to print the maximum length of Bitonic subsequence. 
a subsequenceof array is called Bitonic if it is first increasing, then decreasing.
Input:
First line contains T test cases. First line of every test case consists of N , denoting number of elements in an array. Second line of every test consists of elements in array.
Output:
For each testcase, in a new line, print the length of longest bitonic sequence.
Constraints:
1<=T<=100
1<=N<=100
1<=Ai<=200
Example:
Input:
2
5
1 2 5 3 2
8
1 11 2 10 4 5 2 1
Output:
5
6

SOLUTION:


#include <iostream>
#include<climits>
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
	    
	    int dp[n],dp2[n];
	    
	    for(i=0;i<n;i++)       //LIS
	    {
	        dp[i]=1;
	        for(j=0;j<i;j++)
	        {
	            if(a[i]>a[j])
	            dp[i]=max(dp[i],1+dp[j]);
	        }
	    }
	    
	    for(i=n-1;i>=0;i--)     //LDS
	    {   
	        dp2[i]=1;
	        for(j=n-1;j>i;j--)
	        {
	            if(a[i]>a[j])
	            dp2[i]=max(dp2[i],1+dp2[j]);
	        }
	    }
	    
	    for(i=0;i<n;i++)
	    ans=max(ans,dp[i]+dp2[i]-1);
	     
	    cout<<ans<<endl;
	}
	return 0;
}
