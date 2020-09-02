PROBLEM:



You are given a text and a wildcard pattern. A text contains lowercase English letters only. A wildcard pattern can contain, along with lowercase English letters,
'?' and '*' characters.

'?' matches any single character. For example, Text = "aaba" and Pattern = "aa?a", then they are matched.
' * ' matches any subsegment of characters(including empty sub-segment). For example, Text = "aaba" and Pattern = "a*", then they are matched. Find out if the pattern
and text matches or not.
Input Format
First line contains the Text and the second line contains the Pattern.

Constraints
1<= |Text|, |Pattern| <=1000

Output Format
Print "MATCHED", if the Text and the Pattern matches, and "NOT MATCHED" otherwise.

Sample Input
aaabac
**ab*?
Sample Output
MATCHED





SOLUTION:



#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 

int main()
{   
    ll n,m,i,j;
	string s1,s2;
	cin>>s1>>s2;

	n=s1.size();
	m=s2.size();

	vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
	dp[0][0]=true;

	for(i=1;i<=m;i++)
	{
		if(s2[i-1]=='*')
		dp[0][i]=dp[0][i-1];
	}

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(s1[i-1]==s2[j-1] || s2[j-1]=='?')
			dp[i][j]=dp[i-1][j-1];

			else if(s2[j-1]=='*')
			dp[i][j]=dp[i-1][j] || dp[i][j-1];
		}
	}

	if(dp[n][m])
	cout<<"MATCHED"<<endl;
	else
	cout<<"NOT MATCHED"<<endl;



    return 0;
}
