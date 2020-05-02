PROBLEM:


Dilpreet wants to paint his dog- Buzo's home that has n boards with different lengths[A1, A2,..., An]. He hired k painters for this
work and each painter takes 1 unit time to paint 1 unit of the board.The problem is to find the minimum time to get this job done under
the constraints that any painter will only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but not
board {2, 4, 5}.

Input:
The first line consists of a single integer T, the number of test cases. For each test case, the first line contains an integer k
denoting the number of painters and integer n denoting the number of boards. Next line contains n- space separated integers denoting the
size of boards.

Output:
For each test case, the output is an integer displaying the minimum time for painting that house.

Constraints:
1<=T<=100
1<=k<=30
1<=n<=50
1<=A[i]<=500

Example:
Input:
2
2 4
10 10 10 10
2 4
10 20 30 40
Output:
20
60



SOLUTION:


#include <iostream>
using namespace std;

bool isValid(int a[],int n,int k,int mid)
{
    int worker=1,sum=0;
    
    for(int i=0;i<n;i++)
    {
        if(a[i]>mid)
        return false;
        
        if(sum+a[i]>mid)
        {
            worker++;
            sum=a[i];
            
            if(worker>k)
            return false;
        }
        else
        sum+=a[i];
    }
    
    return true;
}

int binary_search(int a[],int n,int k)
{
    int ans=-1,l=0,h,s=0,mid;
    
    for(int i=0;i<n;i++)
    {
        s+=a[i];
        l=max(l,a[i]);
    }
    h=s;
    
    while(l<=h)
    {
        mid=l+(h-l)/2;
        
        if(isValid(a,n,k,mid))
        {
            ans=mid;
            h=mid-1;
        }
        else
        l=mid+1;
    }
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int k,n,i;
	    cin>>k>>n;
	    
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    
	    cout<<binary_search(a,n,k)<<endl;
	}
	return 0;
}

