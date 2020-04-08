PROBLEM:

Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule
when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the
amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He
asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present
in it.
Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each test case contains an integer
n which denotes the number of houses. Next line contains space separated numbers denoting the amount of money in each house.
Output:
For each testcase, in a newline, print an integer which denotes the maximum amount he can take home.
Constraints:
1 <= T <= 200
1 <= n <= 104
1 <= a[i] <= 104
Example:
Input:
2
6
5 5 10 100 10 5
3
1 2 3
Output:
110
4
Explanation:
Testcase1:
5+100+5=110
Testcase2:
1+3=4


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
	    
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    int dp[n];
	    dp[0]=a[0];
	    if(n>1)
	    {
	        dp[1]=max(a[0],a[1]);
	    }
	    
	    for(i=2;i<n;i++)
	    {
	        dp[i]=max(dp[i-1],dp[i-2]+a[i]);    //max of exclude a[i] and a[i-1]
	    }
	    
	    cout<<dp[n-1]<<endl;
	    
	}
	return 0;
}
