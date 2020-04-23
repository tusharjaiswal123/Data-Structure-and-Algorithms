PROBLEM:

Find nCr for given n and r.

Input:
First line contains number of test cases T. T testcases follow. Each testcase contains 1 line of input containing 2 integers n
and r separated by a space.

Output:
For each testcase, in a new line, find the nCr. Modulus your output to 109+7.

Constraints:
1 <= T <= 50
1 <= n <= 103
1 <= r <= 800

Example:
Input:
2
3 2
4 2
Output:
3
6


SOLUTION:


#include <iostream>
#define MOD 1000000007
#define ulli unsigned long long int
using namespace std;

ulli pow(ulli a,ulli n,ulli m)
{
    ulli ans=1;
    
    while(n)
    {
        if(n%2==1)
        {
            ans=((ans%m)*(a%m))%m;
            n--;
        }
        else
        {
            a=((a%m)*(a%m))%m;
            n=n/2;
        }
    }
    
    return ans%m;
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    ulli n,r,a=1,b,c,d,i,ans;
	    cin>>n>>r;
	    
	    if(n>=r)
	    {
    	    for(i=1;i<=n;i++)
    	    {
    	        a=((a%MOD)*(i%MOD))%MOD;
    	        
    	        if(i==r)
    	        {
    	            b=a;
    	        }
    	        
    	        if(i==n-r)
    	        {
    	            c=a;
    	        }
    	    }
    	    
    	    d=((b%MOD)*(c%MOD)%MOD);
    	    ans = ((a%MOD)*(pow(d,MOD-2,MOD)%MOD)%MOD);
	    }
	    else
	    {
	        ans=0;
	    }     
	    
	    cout<<ans<<endl;
	    
	}
	return 0;
}
