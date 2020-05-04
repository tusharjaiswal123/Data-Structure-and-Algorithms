PROBLEM:

A string is k palindrome if it can be transformed into a palindrome on removing at most k characters from it. Your task is to complete
the function is_k_palin which takes two arguments a string str and a number N . Your function should return true if the string is k
palindrome else it should return false.

Input:
The first line of input is an integer T denoting the number of test cases . Then T test cases follow . Each test case  contains a
string str and an integer N separated by space.  

Output:
The output will be 1 if the string is  k palindrome else 0 .

Constraints:
1<=T<=100
1<=length of str<=100
1<=N<=20

Example:
Input
2
abcdecba 1
acdcb  1
Output
1
0

SOLUTION:

bool is_k_palin(string s,int k)
{
    int n,i,j;
    n=s.length();
    
    string s1=s;                           //Find LPS
    reverse(s1.begin(),s1.end());
    
    int dp[n+1][n+1];
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            
            else if(s[i-1]==s1[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    if(dp[n][n]+k>=n)
    return true;
    else
    return false;
}
