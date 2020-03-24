PROBLEM:

Given two arrays: arr1[0..m-1] of size m and arr2[0..n-1] of size n. Task is to check whether arr2[] is a subset of arr1[] or not. Both the arrays can be both unsorted or sorted. It may be assumed that elements in both array are distinct.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an two integers m and n denoting the size of arr1 and arr2 respectively. The following two lines contains the space separated elements of arr1 and arr2 respectively.

Output:
Print "Yes"(without quotes) if arr2 is subset of arr1.
Print "No"(without quotes) if arr2 is not subset of arr1.

Constraints:
1 <= T <= 100
1 <= m,n <= 105
1 <= arr1[i], arr2[j] <= 105

Example:
Input:
3
6 4
11 1 13 21 3 7
11 3 7 1
6 3
1 2 3 4 5 6
1 2 4
5 3
10 5 2 23 19
19 5 3

Output:
Yes
Yes
No


SOLUTION:

1.Using set  O((m+n)*log(m+n))

#include <iostream>
#include<set>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,m,i,c,d;
	    cin>>m>>n;
	    
	    int a[m],b[n];
	    set<int> s;
	    
	    for(i=0;i<m;i++)
	    {
	        cin>>a[i];
	        s.insert(a[i]);
	    }
	    c=s.size();
	    for(i=0;i<n;i++)
	    {
	        cin>>b[i];
	        s.insert(b[i]);
	    }
	    d=s.size();
	    
	    if(c==d)
	    cout<<"Yes"<<endl;
	    else 
	    cout<<"No"<<endl;
	}
	return 0;
}


2.using binary search

#include <bits/stdc++.h>
using namespace std;

bool binary_search(int a[],int x,int m)
{
    int l=0;
    int h=m-1;
    
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        
        if(a[mid]==x)
        return true;
        
        else if(a[mid]>x)
        h=mid-1;
        
        else
        l=mid+1;
    }
    return false;
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,m,i,c=0;
	    cin>>m>>n;
	    
	    int a[m],b[n];
	    
	    for(i=0;i<m;i++)
	        cin>>a[i];
	        
	    for(i=0;i<n;i++)
	        cin>>b[i];
	    
	    sort(a,a+m);
	    
	    for(i=0;i<n;i++)
	    {
	        if(binary_search(a,b[i],m))
	        c++;
	    }
	    
	    
	    if(c==n)
	    cout<<"Yes"<<endl;
	    else 
	    cout<<"No"<<endl;
	}
	return 0;
}
