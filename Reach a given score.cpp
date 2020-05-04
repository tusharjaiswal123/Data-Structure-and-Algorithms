PROBLEM:

Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to
reach the given score.
Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow.The first line of each test
case is n.
Output:
For each testcase, in a new line, print number of ways/combinations to reach the given score.
Constraints:
1 ≤ T ≤ 100
1 ≤ n ≤ 1000
Example:
Input:
3
8
20
13
Output:
1
4
2



SOLUTION:

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i;
	    cin>>n;
	    
	    int dp[n+1]={0};
	    dp[0]=1;
	    
	    for(i=3;i<=n;i++)
	    {   
	        dp[i]+=dp[i-3];
	    }
	    
	    for(i=5;i<=n;i++)
	    dp[i]+=dp[i-5];
	    
	    for(i=10;i<=n;i++)
	    dp[i]+=dp[i-10];
	    
	    cout<<dp[n]<<endl;
	}
	return 0;
}
