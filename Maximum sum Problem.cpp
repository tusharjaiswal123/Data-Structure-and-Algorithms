PROBLEM:

Given a number n, we can divide it in only three parts n/2, n/3 and n/4 (we will consider only integer part). The task is to find the
maximum sum we can make by dividing number in three parts recursively and summing up them together.
Note: Sometimes, the maximum sum can be obtained by not dividing n.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test
case contains the integer n.
Output:
For each testcase, in a new line, print the maximum sum possible.
Constraints:
1<= T <=100
1<= n <=105
Example:
Input:
2
12 
24
Output:
13 
27

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
	    
	    int dp[n+1];
	    dp[0]=0;
	    
	    for(i=1;i<=n;i++)
	    {
	        dp[i]=max(dp[i/2]+dp[i/3]+dp[i/4],i);
	    }
	    
	    cout<<dp[n]<<endl;
	}
	return 0;
}
