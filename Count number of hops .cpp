#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int dp[n];
	    dp[0]=0;
	    dp[1]=1;
	    dp[2]=2;
	    dp[3]=4;
	    
	    for(int i=4;i<=n;i++)
	    dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	    
	    cout<<dp[n]<<endl;
	}
	return 0;
}
