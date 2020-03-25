PROBLEM:

There are Infinite People Standing in a row, indexed from 1.
A person having index 'i' has strength of (i*i).
You have Strength 'P'. You need to tell what is the maximum number of People You can Kill With your Strength P.
You can only Kill a person with strength 'X' if P >= 'X'  and after killing him, Your Strength decreases by 'X'. 
Input:
First line contains an integer 'T' - the number of testcases,
Each of the next 'T' lines contains an integer 'P'- Your Power.
 
Output:
For each testcase Output The maximum Number of People You can kill.

Constraints:
1<=T<=10000
1<=P<=1000000000000000

Example:
Input:
1
14
Output:
3

SOLUTION:

#include <iostream>
#define ulli unsigned long long int
using namespace std;

ulli sum(ulli n)
{
    return (n*(n+1)*(2*n+1)/6);
}


ulli upper_limit(ulli p)
{
    ulli i=1;
    
    while(sum(i)<p)
    {   
        i=i*2;
    }
    return i;
}

ulli binary_search(ulli p,ulli l,ulli h)
{
    
    while(l<=h)
    {
        ulli m=l+(h-l)/2;
        ulli n=sum(m);
        
        if(n==p || (n<p && sum(m+1)>p))
        return m;
        
        else if(n>p)
        h=m-1;
        
        else
        l=m+1;
    }
    
    return -1;
}

int main() {
	ulli t;
	cin>>t;
	
	while(t--)
	{
	    ulli p,ans;
	    cin>>p;
	    
	    
	    ulli k=upper_limit(p);
	    
	    if(sum(k)==p)
	    ans=k;
	    
	    else
	    ans=binary_search(p,1,k);
	    
	    cout<<ans<<endl;
	}
	return 0;
}
