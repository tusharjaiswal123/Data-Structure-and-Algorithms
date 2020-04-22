PROBLEM:

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2



SOLUTION:

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int s,c=0,l,r,n;
        n=nums.size();
        
        for(l=0;l<n;l++)
        {   
            s=0;
            for(r=l;r<n;r++)
            {
                s+=nums[r];
                if(s==k)
                c++;
            }
        }
        
        return c;
    }
};
