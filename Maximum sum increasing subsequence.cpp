PROBLEM:

Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.
Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N(the size of array). The second line of each test case contains array elements.
Output:
For each test case print the required answer in new line.
Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ Ai ≤ 106
Example:
Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3
Output:
106
10


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
	    
	    int dp[n];
	    
	    for(i=0;i<n;i++)   
	    {   
	        dp[i]=a[i];
	        for(j=0;j<i;j++)
	        {
	            if(a[i]>a[j])
	            {
	                dp[i]=max(dp[i],a[i]+dp[j]);
	            }
	        }
	        ans=max(ans,dp[i]);
	    }
	    
	    cout<<ans<<endl;
	    
	}
	return 0;
}
