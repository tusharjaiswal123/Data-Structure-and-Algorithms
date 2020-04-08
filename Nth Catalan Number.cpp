PROBLEM:

Given a number N. The task is to find the nth catalan number.
The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
Input:
First line of input contains a single integer T which denotes the number of test cases. First line of each test case contains a single
integer N.
Output:
For each test case, in a new line print the catalan number at position N.
Note: Positions start from 0 as shown above.
Constraints:
1 <= T <= 100
1 <= N <= 100
Example:
Input:
3
5
4
10
Output:
42
14
16796


SOLUTION:

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp> 
using boost::multiprecision::cpp_int;
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,j;
	    cin>>n;
	    
	    cpp_int dp[n+1];
	    
	    dp[0]=1;
	    dp[1]=1;
	    
	    for(i=2;i<=n;i++)
	    {
	        dp[i]=0;
	        for(j=0;j<i;j++)
	        {
	            dp[i]+=dp[j]*dp[i-j-1];
	        }
	    }
	    
	    cout<<dp[n]<<endl;
	}
	return 0;
}
