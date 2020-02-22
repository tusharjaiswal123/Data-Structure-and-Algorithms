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
	    
	    for(int i=1;i<=n;i++)
	    {
	    if(i%2==0)
	    dp[i]=1+min(dp[i-1],dp[i/2]);
	    else
	    dp[i]=1+dp[i-1];
	    }
	    
	    cout<<dp[n]<<endl;
	}
	return 0;
}
