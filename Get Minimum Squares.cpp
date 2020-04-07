PROBLEM:

Given a number N. You need to write a program to print the minimum number of squares of this number that sums to N. For Example: If N = 100 , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as minimum number of square is 1 , i.e (10*10).

Input:
First line of input contains a single integer T, which denotes the number of test cases. Then T test cases follows. First line of each test case contains a single integer N.
Output:
For each test case print the minimum number of squares that sums to N.

Constraints:
1<=T<=100
1<=N<=104

Example:
Input:
3
100
6
25
Output:
1
3
1

SOLUTION:

#include <bits/stdc++.h>
using namespace std;

const int INF=1e9+5;
int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,j,c=0;
	    cin>>n;
	    
	    vector<int> v;
	    
	    for(i=1;i*i<=n;i++)
	    {
	        v.push_back(i*i);
	        c++;
	    }      
	    
	    int dp[n+1];
	    dp[0]=0;
	    
	    for(i=1;i<=n;i++)
	    dp[i]=INF;
	    
	    for(j=0;j<c;j++)
	    {
	        for(i=1;i<=n;i++)
	        {
	            if(i>=v[j])
	            dp[i]=min(dp[i],1+dp[i-v[j]]);
	        }
	    }
	    
	    cout<<dp[n]<<endl;
	    
	}
	return 0;
}
