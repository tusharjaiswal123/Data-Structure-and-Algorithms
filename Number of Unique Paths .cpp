#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,m,i,j;
	    cin>>m>>n;
	    
	    int dp[m][n];
	    dp[0][0]=1;
	    
	    for(j=1;j<n;j++)
	    dp[0][j]=1;
	    
	    for(i=1;i<m;i++)
	    dp[i][0]=1;
	    
	    for(i=1;i<m;i++)
	    {
	        for(j=1;j<n;j++)
	        dp[i][j]=dp[i-1][j]+dp[i][j-1];
	    }
	    
	    cout<<dp[m-1][n-1]<<endl;
	}
	return 0;
}
