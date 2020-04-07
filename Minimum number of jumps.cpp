PROBLEM:

Given an array of integers where each element represents the max number of steps that can be made forward from that element. The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.
Input: 
The first line contains an integer T, depicting total number of test cases.  Then following T lines contains a number n denoting the size of the array. Next line contains the sequence of integers a1, a2, ..., an.
Output:
For each testcase, in a new line, print the minimum number of jumps. If answer is not possible print "-1"(without quotes).
Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 <= ai <= 107
Example:
Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
Output:
3
2


SOLUTION:

#include <iostream>
using namespace std;

const int INF=1e9+5;
int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,j;
	    cin>>n;
	    
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    int dp[n];
	    dp[0]=0;
	    
	    for(i=1;i<n;i++)
	    {   
	        dp[i]=INF;
	        for(j=0;j<i;j++)
	        {   
	            if(a[j]>=i-j)
	            dp[i]=min(dp[i],dp[j]+1);
	        }
	    }
	    
	    
	    if(dp[n-1]==INF)
	    cout<<-1<<endl;
	    
	    else
	    cout<<dp[n-1]<<endl;
	   
	    
	}
	return 0;
}
