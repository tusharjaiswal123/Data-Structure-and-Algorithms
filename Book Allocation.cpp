PROBLEM:


You are given N number of books. Every ith book has Pi number of pages. 
You have to allocate books to M number of students. There can be many ways or permutations to do so. In each permutation one of the M
students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation
in which the maximum number of pages allocated to a student is minimum of those in all the other permutations, and print this minimum
value. 
Each book will be allocated to exactly one student. Each student has to be allocated atleast one book.
Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see explanation for better
understanding).

Input:
The first line contains 'T' denoting the number of testcases. Then follows description of T testcases:Each case begins with a single
positive integer N denoting the number of books.The second line contains N space separated positive integers denoting the pages of each
book.And the third line contains another integer M, denoting the number of students.

Output:
For each test case, output a single line containing minimum number of pages each student has to read for corresponding test case.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A [ i ] <= 106
1 <= M <= 106

Example:
Input:
2
4
12 34 67 90
2
3
15 17 20
2
Output:
113
32


SOLUTION:


#include <bits/stdc++.h>
using namespace std;

bool isValid(long long a[],long long n,long long m,long long mid)
{   
 
    int sum=0,student=1;
    for(int i=0;i<n;i++)
    {   
        if(a[i]>mid)
        return false;
        
        if(sum + a[i] > mid)
        {
            student++;
            sum=a[i];
            
            if(student>m)
            return false;
        }
        else
        sum+=a[i];
    
    }
    
    return true;
    
}

int binary_search(long long a[],long long n,long long m)
{
    long long ans=-1,l=0,h,s=0,mid,i;
    
    for(i=0;i<n;i++)
    {
        s+=a[i];
        l=max(l,a[i]);
    }
    
    h=s;
    
    while(l<=h)
    {
        mid=l+(h-l)/2;
    
        if(isValid(a,n,m,mid))
        {
            ans=mid;
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    
    return ans;
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    long long n,m,i;
	    cin>>n;
	    
	    long long a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    cin>>m;
	    
	     if(m>n)
         cout<<-1<<endl;
         else
	     cout<<binary_search(a,n,m)<<endl;
	}
	return 0;
}
