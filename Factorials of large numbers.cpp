PROBLEM:

Given an integer, the task is to find factorial of the number.
 
Input:
The first line of input contains an integer T denoting the number of test cases.  
The first line of each test case is N,the number whose factorial is to be found
 
Output:
Print the factorial of the number in separate line.
 
Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
 
Example:
Input
3
5
10
2
 
Output
120
3628800
2


SOLUTION:


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,j,s,carry,p;
	    cin>>n;
	    
	    vector<int> v;
	    v.push_back(1);
	    s=1;
	    
	    for(i=2;i<=n;i++)
	    {   
	        carry=0;
	        for(j=0;j<s;j++)
	        {
	            p=i*v[j]+carry;
	            v[j]=p%10;
	            carry=p/10;
	        }
	        
	        while(carry)
	        {
	            v.emplace_back(carry%10);
	            carry=carry/10;
	            s++;
	        }
	    }
	    
	    for(i=v.size()-1;i>=0;i--)
	    cout<<v[i];
	    
	    cout<<endl;
	}
	return 0;
}
