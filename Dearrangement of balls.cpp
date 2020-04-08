PROBLEM:

You are given N balls numbered from 1 to N and there are N baskets numbered from 1 to N in front of you, the ‘i’th basket is meant for 
the ‘i’th ball. The task is to calculate the number of ways in which none of the balls goes into their respective basket.
Input: The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case 
consist of a single line containing an integer N.
Output: Corresponding to each test case, print the desired output in a new line. Since the answer can be large, print it modulo 109 + 7.
Constraints :               
1 ≤ T ≤ 100
1 ≤ N ≤ 105
Examples
Input :
2
2
3
Output :
1
2


#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    long long n,ans=1,i;
	    cin>>n;
	    
	    int dp[n+1];
	    
	    dp[0]=1;
	    dp[1]=0;
	    dp[2]=1;
	    
	    for(i=3;i<=n;i++)
	    {
	        dp[i] =  ( ((i-1)%MOD) * (dp[i-1] + dp[i-2])%MOD)%MOD;
	    }
	    
	    cout<<dp[n]%MOD<<endl;
	}
	return 0;
}
