PROBLEM:

Given an array of integers of size N and a number K. Your must modify array K number of times. Here modify array means in each operation you can replace any array element either arr[i] by -arr[i] or -arr[i] by arr[i]. You need to perform this operation in such a way that after K operations, sum of array must be maximum.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines . The first line of each test case contains an integer N and K. The second line of each test case contains N space separated integers denoting elements of the array.
Output:
For each test case, print maximum possible sum.
Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
-1018 ≤ Ai ≤ 1018
Example:
Input:
2
5 1
1 2 -3 4 5
10 5
5 -2 5 -4 5 -12 5 5 5 20
Output:
15
68

SOLUTION:

#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    long long n,k,i,mn=INT_MAX,s=0;
	    cin>>n>>k;
	    
	    long long a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    if(k<n)
	    sort(a,a+n);
	    
	    for(i=0;i<n;i++)
	    {
	        if(k>0 && a[i]<0)
	        {
	            a[i]=-a[i];
	            k--;
	        }
	        mn=min(mn,a[i]);
	        s+=a[i];
	    }
	    
	    if(k>0 && k%2==1)
	    {
	        s=s-2*mn;
	    }
	    
	    cout<<s<<endl;
	    
	}
	
	return 0;
}
