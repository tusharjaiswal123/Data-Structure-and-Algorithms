PROBLEM:

There are N stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does matter).
Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, an integer N will be given.
Output:
For each testcase, in a new line, print number of possible ways to reach Nth stair. Answer your output % 10^9+7.
Constraints:
1<=T<=105
1<=N<=105
Example:
Input:
3
4
10
24
Output:
5
89
75025


SOLUTION:

#include <iostream>
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(false);cout.tie(false);
using namespace std;

int main() {
    fastio;
    
    int dp[100001];
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	    
	for(int i=3;i<=100001;i++)
	dp[i]=(dp[i-1]%MOD+dp[i-2]%MOD)%MOD;
	    
    
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<dp[n]%MOD<<endl;
	}
	return 0;
}
