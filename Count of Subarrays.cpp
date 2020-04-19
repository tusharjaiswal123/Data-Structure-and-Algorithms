PROBLEM:


Given an array of N positive integers  a1, a2 ............ an. The value of each contiguous subarray of given array is the maximum
element present in that subarray. The task is to return the number of subarrays having value strictly greater than K.

Input:
The first line of the input contains 'T' denoting the total number of testcases. Then follows the description of testcases. The first
line of each testcase contains two space separated positive integers N and K denoting the size of array and the value of K. The second
line contains N space separated positive integers denoting the elements of array.
Output:
Output the number of subarrays having value strictly greater than K.

Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= a[i] <= 105

Example:
Input: 
2
3 2
3 2 1
4 1
1 2 3 4
Output:
3
9


SOLUTION:

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k,i,c=0,l,r,s;
        cin>>n>>k;
        
        int a[n];
        
        for(i=0;i<n;i++)
        cin>>a[i];
        
        
        for(l=0;l<n;l++)
        {   
            s=INT_MIN;
            for(r=l;r<n;r++)
            {
                s=max(s,a[r]);
                if(s>k)
                c++;
            }
        }
        
        cout<<c<<endl;
    }
	return 0;
}


