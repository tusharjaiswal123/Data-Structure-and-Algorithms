PROBLEM:

Given a string, find the length of the longest substring without repeating characters.
Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
             
           
SOLUTION:

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n,i,j,ans=INT_MIN,c=0;
        n=s.length();
        
        if(n==0)
            return 0;
        
        int dp[n];
        
        unordered_set<char> st;  
    
        
        for(i=0;i<n;i++)
        {
            st.insert(s[i]);
            for(j=i-1;j>=0;j--)
            {
                if(st.find(s[j])!=st.end())
                {
                    break;
                }
                else
                st.insert(s[j]);
            }
            
            dp[i]=st.size();
            st.clear();
            
            ans=max(ans,dp[i]);
        }
        
        //for(i=0;i<n;i++)
        //    cout<<dp[i]<<" ";
        
        
        return ans;
        
    }
};
