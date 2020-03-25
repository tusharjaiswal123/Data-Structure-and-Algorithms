PROBLEM:

Given an array of n distinct elements. Check whether the given array is a k sorted array or not. A k sorted array is an array where each element is at most k distance away from its target position in the sorted array.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the array. The next line contains n space separated integers forming the array. The last line contains k.
Output:
Print "Yes" if the array is a k sorted array.
Print "No" if the array is not a k sorted array.
Constraints:
1<=T<=10^5
1<=n<=10^5
1<=a[i]<=10^5
1<=k<=n
Example:
Input:
2
6
3 2 1 5 6 4
2
7
13 8 10 7 15 14 12
3
Output:
Yes
No


SOLUTION:

#include <bits/stdc++.h>
using namespace std;

int binary_search(int b[],int x,int n)
{
    int l=0;
    int h=n-1;
    
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        
        if(b[mid]==x)
        return mid;
        
        else if(b[mid]>x)
        h=mid-1;
        
        else
        l=mid+1;
    }
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,k,i,flag=1;
	    cin>>n;
	    
	    int a[n],b[n];
	    
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	        b[i]=a[i];
	    }
	    cin>>k;
	    
	    sort(b,b+n);
	    
	    for(i=0;i<n;i++)
	    {
	        int j=binary_search(b,a[i],n);
	        if(abs(j-i)>k)
	        {
	            flag=0;
	            break;
	        }
	    }
	    
	    if(flag==1)
	    cout<<"Yes"<<endl;
	    else
	    cout<<"No"<<endl;
	}
	return 0;
  
  }
