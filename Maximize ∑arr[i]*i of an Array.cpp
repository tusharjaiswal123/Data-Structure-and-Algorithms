PROBLEM:

Given an array A of N integers. Your task is to write a program to find the maximum value of ∑arr[i]*i, where i = 0, 1, 2,…., n – 1.
You are allowed to rearrange the elements of the array.
Note: Since output could be large, hence module 109+7 and then print answer.
Input:
First line of the input contains an integer T, denoting the number of test cases. Then T test case follows. Each testcase contains two lines of input. First line contains an integer N, denoting the size of the array. Next line contains N space separated integers denoting the elements of the array.
Output:
For each test case, print the required answer on a new line.
Constraints:
1 <= T <= 103
1 <= N <= 107
1 <= Ai <= N
Example:
Input:
2
5
5 3 2 4 1
3
1 2 3
Output:
40
8


SOLUTION:

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,s=0;
	    cin>>n;
	    
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    sort(a,a+n);
	    
	    for(i=0;i<n;i++)
	    {
	        s = (s + ( (i%MOD) * (a[i]%MOD) )%MOD)%MOD;
	    }
	    
	    cout<<s<<endl;
	}
	return 0;
}
