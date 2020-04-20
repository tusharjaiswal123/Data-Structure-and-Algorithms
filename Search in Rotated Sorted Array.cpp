PROBLEM:

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).
Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

SOLUTION:

int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        int l,r,mid,ans=-1,value;
        l=0;
        r=n-1;
        
        while(l<=r)
        {
            mid=l+(r-l)/2;
            value=nums[mid];
            
            if(value==target)    //if found return index
            {
                ans=mid;
                break;
            }
            
            else if(value>target)
            {
                if(nums[0]<=value)         //we are in sorted part
                {
                    if(target>=nums[0])    //target is between index 0 and mid
                        r=mid-1;
                    else
                        l=mid+1;           //target is in other sorted part
                }
                else                       //we are in second part
                {
                    r=mid-1;               //target will be in lefft side of mid
                }
            }
            
            else if(value<target)       
            {
                if(nums[0]<=value)         //1st part
                {
                    l=mid+1;              
                }
                else
                {
                    if(nums[0]<=target)    
                        r=mid-1;
                    else
                        l=mid+1;
                }
            }
              
        }
        
        return ans;
        
    }
