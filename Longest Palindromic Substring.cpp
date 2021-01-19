PROBLEM:


Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: "cbbd"
Output: "bb"


SOLUTION:

class Solution {
public:
    string longestPalindrome(string s) {    //O(n^2)
        
        string ans="";
        int max_len=0;
        int n=s.length();
        
        for(int mid=0;mid<n;mid++)     //odd length palindromic substring
        {
            for(int x=0;mid-x>=0 && mid+x<n;x++)
            {
                if(s[mid-x]!=s[mid+x])
                {   
                    break;
                }
                
                int len=2*x+1;
                if(len>max_len)
                {
                    max_len=len;
                    ans=s.substr(mid-x,len);
                }
                
            }
        }
        
        for(int mid=0;mid<n-1;mid++)    //even length palindromic substring
        {
            for(int x=1;mid-x+1>=0 && mid+x<n;x++)
            {
                if(s[mid-x+1]!=s[mid+x])
                {
                    break;
                }
                int len=2*x;
                if(len>max_len)
                {
                    max_len=len;
                    ans=s.substr(mid-x+1,len);
                }
            }
            
        }
        return ans;
    }
};



DP:

class Solution {
public:
    string longestPalindrome(string s) {
        
        int i,j,n,mx=1,l;
        string ans;
        n=s.size();
        l=0;
        
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        for(i=0;i<n;i++)
            dp[i][i]=true;
        
        for(j=0;j<n;j++)
        {
            for(i=0;i<j;i++)
            {
                if( (s[j] == s[i] && dp[i+1][j-1]) || (s[i]==s[j] && j==i+1))
                {
                    dp[i][j]=true;
                    if(j-i+1>mx)
                    {
                        mx=j-i+1;
                        l=i;
                    }
                }
            }
        }
    
        ans = s.substr(l,mx);
        
        return ans;
    }
};
