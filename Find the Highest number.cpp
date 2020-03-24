PROBLEM:

Given an array in such a way that the elements stored in array are in increasing order initially and then after reaching to a peak element , elements stored are in decreasing order. Find the highest element.
Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case consists of an integer n. The next line consists of n spaced integers. 
Output:
Print the highest number in the array.
Constraints: 
1<=T<=100
1<=n<=200
1<=a[i]<=105
Example:
Input:
2
11
1 2 3 4 5 6 5 4 3 2 1
5
1 2 3 4 5 
Output:
6
5


SOLUTION:

#include <iostream>
using namespace std;

int binary_search(int a[],int n,int l,int h)
{
    while(l<=h)
    {
    int mid=l+(h-l)/2;
    
    if( (mid==0 && a[mid]>a[mid+1]) || (mid==n-1 && a[mid]>a[mid-1]) || (a[mid]>a[mid-1] && a[mid]>a[mid+1]) )
    return mid;
    
    else if(a[mid]>a[mid-1] && a[mid]<a[mid+1])
    l=mid+1;
    
    else if(a[mid]>a[mid+1] && a[mid]<a[mid-1])
    h=mid-1;
    }
    
    return -1;
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i;
	    cin>>n;
	    
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    int k=binary_search(a,n,0,n-1);
	    
	    cout<<a[k]<<endl;
	}
	return 0;
}
