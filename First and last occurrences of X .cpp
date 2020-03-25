PROBLEM:

Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.
Note: If the number x is not found in the array just print '-1'.
Input:
The first line consists of an integer T i.e number of test cases. The first line of each test case contains two integers n and x. The second line contains n spaced integers.
Output:
Print index of the first and last occurrences of the number x with a space in between.
Constraints: 
1<=T<=100
1<=n,a[i]<=1000
Example:
Input:
2
9 5
1 3 5 5 5 5 67 123 125
9 7
1 3 5 5 5 5 7 123 125
Output:
2 5
6 6

SOLUTION:

#include <iostream>
using namespace std;

int binary_search_left(int a[],int n,int x)
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
            h=mid-1;
        }
        
        else if(a[mid]<x)
        l=mid+1;
        
        else if(a[mid]>x)
        h=mid-1;
    }
    return ans;
}

int binary_search_right(int a[],int n,int x)
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
            l=mid+1;
        }
        
        else if(a[mid]>x)
        h=mid-1;
        
        else if(a[mid]<x)
        l=mid+1;
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
	    
	    int u=binary_search_left(a,n,x);
	    int v=binary_search_right(a,n,x);
	    
	    if(u==-1 || v==-1)
	    cout<<-1<<endl;
	    
	    else
	    cout<<u<<" "<<v<<endl;
	}
	return 0;
}
