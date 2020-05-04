PROBLEM:

You need to write N same characters on a screen and each time you can insert a character, delete the last character and copy and paste
all written characters i.e. after copy operation count of total written character will become twice. Now you are given time for
insertion, deletion and copying. You need to output minimum time to write N characters on the screen using these operations.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an
integer N denoting the number of same characters to write on screen. The next line contains time for insertion, deletion and copying
respectively.
Output:
Print the minimum to write N characters on the screen.
Constraints:
1<=T<=100
1<=N<=100
1<=insert,remove,copy<=N
Example:
Input:
2
9
1 2 1
10
2 5 4
Output:
5
14

SOLUTION:

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,a,b,c;
	    cin>>n;
	    
	    cin>>a>>b>>c;
	    
	    int dp[n+2];
	    dp[0]=0;
	    dp[1]=a;
	    
	    for(i=2;i<=n+1;i++)
	    {   
	        dp[i]=dp[i-1]+a;
	        if(i%2==0)
	        {
	            dp[i]=min(dp[i],dp[i/2]+c);
	        }
	        dp[i-1]=min(dp[i-1],dp[i]+b);
	    }
	    
	    cout<<dp[n]<<endl;
	}
	return 0;
}
