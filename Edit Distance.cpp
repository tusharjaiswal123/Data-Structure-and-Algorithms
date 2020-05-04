PROBLEM:

Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to
convert ‘str1′ into ‘str2′.
Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.
Input:
The First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each tese case consists
of two lines. The first line of each test case consists of two space separated integers P and Q denoting the length of the strings str1
and str2 respectively. The second line of each test case coantains two space separated strings str1 and str2 in order.
Output:
Corresponding to each test case, print in a new line, the minimum number of operations required.
Constraints:
1 <= T <= 50
1 <= P <= 100
1 <= Q <= 100
Example:
Input:
1
4 5
geek gesek
Output:
1


SOLUTION:

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,m,i,j;
	    cin>>n>>m;
	    
	    string s1,s2;
	    cin>>s1>>s2;
	    
	    int dp[n+1][m+1];
	    
	    
	    for(i=0;i<=n;i++)
	    {
	        for(j=0;j<=m;j++)
	        {
	            if(i==0)
	            dp[i][j]=j;
	            
	            else if(j==0)
	            dp[i][j]=i;
	            
	            else if(s1[i-1]==s2[j-1])
	            dp[i][j]=dp[i-1][j-1];
	            
	            else
	            dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});  //Insert , Delete, Replace
	        }
	    }
	    
	    cout<<dp[n][m]<<endl;
	}

	return 0;
}
