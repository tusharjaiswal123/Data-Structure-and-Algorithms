PROBLEM:

Given an array of n elements. Consider array as circular array i.e element after an is a1. The task is to find maximum sum of the difference between consecutive elements with rearrangement of array element allowed i.e after rearrangement of element find |a1 – a2| + |a2 – a3| + …… + |an – 1– an| + |an – a1|.
Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains the number of elements in the array a[] as n and next line contains space separated n elements in the array a[].

Output:
Print an integer which denotes the maximized sum.

Constraints:
1<=T<=100
1<=n<=10000
1<=a[i]<=100000​

Example:
Input:
2
4
4 2 1 8
3
10 12 15​
Output:
18​
10

SOLUTION:

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,s=0;
	    cin>>n;
	    
	    int a[n];
	    vector<int> v;
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    sort(a,a+n);
	    
	    for(i=0;i<n/2;i++)
	    {
	        v.push_back(a[i]);
	        v.push_back(a[n-i-1]);
	    }
	    
	    if(n%2==1)
	    v.push_back(a[n/2]);
	    
	    /*for(i=0;i<n;i++)
	    cout<<v[i]<<" ";
	    
	    cout<<endl;*/
	    
	    for(i=0;i<n-1;i++)
	    {
	        s+=abs(v[i+1]-v[i]);
	    }
	    
	    s+=abs(v[n-1]-v[0]);
	    
	    
	    cout<<s<<endl;
	}
	return 0;
}
