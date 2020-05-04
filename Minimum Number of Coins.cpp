PROBLEM:

Given a value V. You have to make change for V cents, given that you have infinite supply of each of C{ C1, C2, .. , Cm} valued coins.
Find the minimum number of coins to make the change.
Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is V and N, V is the
value of cents and N is the number of coins. The second line of each test case contains N input C[i], value of available coins.
Output:
Print the minimum number of coins to make the change, if not possible print "-1".
Constraints:
1 ≤ T ≤ 100
1 ≤ V ≤ 106
1 ≤ N ≤ 106
1 ≤ C[i] ≤ 106
Example:
Input:
1
7 2
2 1
Output:
4

SOLUTION:

#include <iostream>
using namespace std;

const int INF=1e9+5;
int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int v,n,i,j;
	    cin>>v>>n;
	    
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    int dp[v+1];
	    dp[0]=0;
	    
	    for(i=1;i<=v;i++)
	    dp[i]=INF;
	    
	    for(j=0;j<n;j++)
	    {
	        for(i=1;i<=v;i++)
	        {   
	            if(i>=a[j])
	            dp[i]=min(dp[i],1+dp[i-a[j]]);
	        }
	    }
	    
	    if(dp[v]==INF)
	    cout<<-1<<endl;
	    else
	    cout<<dp[v]<<endl;
	}
	return 0;
}
