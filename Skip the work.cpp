PROBLEM:


Given an array A[ ] denoting the time taken to complete N tasks, determine the minimum amount of time required to finish the tasks
considering that you can skip any task, but skipping two consecutive tasks is forbidden.
 

For example 
For the array arr [] = {10, 5, 2, 4, 8, 6, 7, 10}
the output will be  22  (Skip the tasks taking more time ,avoiding consective skipping(10,8,10). Tasks done in: 5+2+4+6+7)
 

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains a positve integer N, denoting the length of the array A[ ].
The second line of each test case contains a N space seprated positve integers, denoting the elements of the array A[ ].


Output
Print out the minimum time taken to complete the tasks.
 

Constraints
1 <= T <= 100
0 <   N <= 30
0 <= A[ ] <= 1000
 

Examples 

Input
4
4
10 5 7 10
6
5 6 7 8 9 10
2
10 20
5
22 10 15 3 5

Output
12
21
10
13



SOLUTION:


#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,ans,in,ex,temp;
	    cin>>n;
	    
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    in=a[0];
	    ex=0;
	    
	    for(i=1;i<n;i++)
	    {   
	        temp=a[i]+min(in,ex);
	        
	        ex=in;
	        in=temp;
	    }
	    
	    cout<<min(in,ex)<<endl;
	    
	}
	return 0;
}
