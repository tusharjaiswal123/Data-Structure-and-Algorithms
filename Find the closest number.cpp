PROBLEM:

Given an array of sorted integers. The task is to find the closest value to the given number in array. Array may contain duplicate values.
Note: If the difference is same for two values print the value which is greater than the given number.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains two integers N & K and the second line contains N space separated array elements.
Output:
For each test case, print the closest number in new line.
Constraints:
1<=T<=100
1<=N<=105
1<=K<=105
1<=A[i]<=105
Example:
Input:
2
4 4
1 3 6 7
7 4
1 2 3 5 6 8 9
Output:
3
5

SOLUTION:

#include <iostream>
using namespace std;

int binary_search_lower(int a[],int n,int x)
{   
    int l=0;
    int h=n-1;
    int ans=-1;
    
    while(l<=h)
    {   
        int mid=l+(h-l)/2;
        if(a[mid]==x)
        {
            ans=mid;
            break;
        }
        
        else if(a[mid]<x)
        {
            ans=mid;
            l=mid+1;
        }
        else if(a[mid]>x)
        h=mid-1;
    }
    
    return ans;
}

int binary_search_upper(int a[],int n,int x)
{
    int l=0;
    int h=n-1;
    int ans=-1;
    
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        
        if(a[mid]==x)
        {
            ans=mid;
            break;
        }
        
        else if(a[mid]<x)
        l=mid+1;
        
        else if(a[mid]>x)
        {
            ans=mid;
            h=mid-1;
        }
    }
    return ans;
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,x;
	    cin>>n>>x;
	    
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    int u=binary_search_lower(a,n,x);
	    int v=binary_search_upper(a,n,x);
	    
	    if(u==-1)
	    cout<<a[v]<<endl;
	    
	    else if(v==-1)
	    cout<<a[u]<<endl;
	    
	    else
	    { 
	        if( abs(x-a[v]) <= abs(x-a[u]) )
	        cout<<a[v]<<endl;
	        else
	        cout<<a[u]<<endl;
	    }
	    
	}
	return 0;
}
