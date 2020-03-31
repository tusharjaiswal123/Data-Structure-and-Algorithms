PROBLEM:

You are given a string of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the length of the string.
The second line of each test case contains the string consisting of '[' and ']'.

Output:
Print the minimum number of swaps to make the string balanced for each test case in a new line.

Constraints:
1<= T <=100
1<= N <=100000
 
Example:
Input  : []][][
Output : 2
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

Input  : [[][]]
Output : 0
String is already balanced.


SOLUTION:

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,c=0,sum=0,p=0;
	    cin>>n;
	    
	    string s;
	    cin>>s;
	    
	    vector<int> v;
	    
	    for(i=0;i<n;i++)
	    {
	        if(s[i]=='[')
	        v.push_back(i);
	    }
	    
	    for(i=0;i<n;i++)
	    {
	        if(s[i]=='[')
	        {
	            c++;
	            p++;
	        }
	        else if(s[i]==']')
	        {
	            c--;
	        }
	        
	        if(c<0)
	        {
	            sum+=v[p]-i;
	            swap(s[i],s[v[p]]);
	            p++;
	            c=1;
	        }
	        
	    }
	    
	    cout<<sum<<endl;
	}
	return 0;
}
