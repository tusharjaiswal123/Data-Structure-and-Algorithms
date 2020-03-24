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

int binary_search(int a[],int n,int x)
{   
    if(x<a[0])
    return 0;
    
    if(x>a[n-1])
    return n-1;
    
    int l=0;
    int h=n-1;
    int mid=0;
    
    while(l<=h)
    {
        mid=l+(h-l)/2;
        
        if(a[mid]==x)
        return mid;
        
        else if(a[mid]<x)
        {
            if(mid+1<n && a[mid+1]>x)
            {
                if((a[mid+1]-x)<=(x-a[mid]))
                return mid+1;
                else
                return mid;
            }
            l=mid+1;
        }
        else if(a[mid]>x)
        {
            if(mid-1>=0 && a[mid-1]<x)
            {
                if((a[mid]-x)<=(x-a[mid-1]))
                return mid;
                else
                return mid-1;
            }
            h=mid-1;
        }
    }
    return mid;
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
	    
	    int ans=binary_search(a,n,x);
	    
	    cout<<a[ans]<<endl;
	}
	return 0;
}
