PROBLEM:


Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an
integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the
array.

Output:
In each seperate line print minimum absolute difference.

Constraints:
1<=T<=30
1<=N<=50
1<=A[I]<=50

Example:
Input:
2
4
1 6 5 11
4
36 7 46 40
Output : 
1
23


SOLUTION:


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,j,s=0,ans=INT_MAX;
	    cin>>n;
	    
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    for(i=0;i<n;i++)
	    s+=a[i];
	    
	    bool dp[s+1];    //dp[i] represent that sum i can be made or not
	    
	    for(i=1;i<=s;i++)
	    dp[i]=false;
	    
	    dp[0]=true;
	    
	    for(i=0;i<n;i++)
	    {   
	        int curr=a[i];
	        for(j=s;j>=a[i];j--)
	        {
	            if(dp[j]==true || dp[j-curr]==false)
	            continue;
	            else
	            dp[j]=true;
	        }
	    }
	    
	    
	    for(i=0;i<s;i++)
	    {   
	        if(dp[i]==true)
	        ans=min(ans,abs(i-(s-i)));     
	    }
	    
	    cout<<ans<<endl;
	}
	return 0;
}
