PROBLEM:

Given a string s, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.

Note: Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.


Examples:

Input  : abbc
Output : 3
Subsequences are abc, abc and abbc

Input  : abcabc
Output : 7
Subsequences are abc, abc, abbc, aabc
abcc, abc and abc


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains
a string s.

Output:
For each test case in a new line print the required output.

Constraints:
1<=T<=100
1<=Length of string <=100

Example:
Input:
2
abbc
abcabc
Output:
3
7


SOLUTION:


#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,a=0,b=0,c=0;
	    string s;
	    cin>>s;
	    
	    n=s.length();
	    
	    for(i=0;i<n;i++)
	    {
	        if(s[i]=='a')
	        a+=(a+1);
	        
	        else if(s[i]=='b')
	        b+=(a+b);
	        
	        else if(s[i]=='c')
	        c+=(b+c);
	        
	    }
	    
	    cout<<c<<endl;
	}
	return 0;
}
