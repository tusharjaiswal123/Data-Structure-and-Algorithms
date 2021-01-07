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
        
        int i,j,n,ans=0;
        n = s.size();
        

        vector<bool> vis(256,false);
        j=0;
        
        for(i=0;i<n;i++)
        {
            if(vis[s[i]]==true)
            {
                while(j<i && vis[s[i]]==true)
                {
                    vis[s[j]]=false;
                    j++;
                }
                
            }
            
            vis[s[i]]=true;
            ans=max(ans,i-j+1);
        }
        
        
        return ans;
    }
};

