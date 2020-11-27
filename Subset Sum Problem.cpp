PROBLEM:

Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.
Input:
The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. First line contains
 'N', representing the number of elements in the set and the second line contains the elements of the set.
Output: 
Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO.
Constraints: 
1 <= T <= 100
1 <= N <= 100
0 <= arr[i] <= 1000
Example:
Input:
2
4
1 5 11 5
3
1 3 5 
Output:
YES
NO


SOLUTION:


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,s=0,j;
	    cin>>n;
	    
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    for(i=0;i<n;i++)
	    s+=a[i];
	    
	    bool ans=false;
	    
	    if(s%2==0)
	    {   
	        int m=s/2;
	        bool dp[n+1][m+1];      //dp[i][j] represents that sum j can be made or not 
	                                //using elements upto index i 
	        dp[0][0]=true;
	        
	        for(j=1;j<=m;j++)
	        dp[0][j]=false;        //without using any element we cannot make sum 
	                               //greater than 0
	        for(i=1;i<=n;i++)
	        {
	            for(j=0;j<=m;j++)
	            {
	                if(a[i-1]>j)       //1 based indexing
	                {
	                    dp[i][j]=dp[i-1][j];
	                }
	                else
	                {
	                    int need=j-a[i-1];
	                    if(dp[i-1][j]==true || dp[i-1][need]==true)
	                    dp[i][j]=true;
	                    
	                    else
	                    dp[i][j]=false;
	                }
	            }
	        }
	        
	        ans=dp[n][m];
	    }
	    
	    if(ans==true)
	    cout<<"YES"<<endl;
	    else
	    cout<<"NO"<<endl;
	    
	}   
	    
	return 0;
}



O(sum) space complexity:


class Solution {
public:
    bool canPartition(vector<int>& nums) {
    
        int i,j,n,s=0;
        n=nums.size();
        
        for(i=0;i<n;i++)
            s+=nums[i];
        
        if(s%2==1)
            return false;
        
        vector<bool> dp(s+1,false);
        dp[0]=true;
        
        for(i=0;i<n;i++)
        {
            for(j=s;j>=nums[i];j--)
            {
                if(dp[j-nums[i]])
                    dp[j]=true;
            }
        }
       
        return dp[s/2];
    }
};




time complexity O(n) and space complexity O(max sum/4) solution using bitwise:


class Solution {
public:
    bool canPartition(vector<int>& nums) {
    
        int i,j,n,s=0;
        n=nums.size();
        
        for(i=0;i<n;i++)
            s+=nums[i];
        
        if(s%2==1)
            return false;
        
        bitset<20001> b(1);
        
        for(i=0;i<n;i++)
        {
            b = b | (b<<nums[i]);
    
            
            if(b[s/2])
                return true;
        }
       
        return b[s/2];
    }
};
