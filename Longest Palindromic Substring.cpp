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
