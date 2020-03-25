PROBLEM:

Given an unsorted array Arr[] and a number N. You need to write a program to find if there exists a pair of elements in the array whose difference is N.
Input:
First line of input contains an integer T which denotes the number of test cases. Then T test cases follows. First line of each test case contains two space separated integers L and N where L denotes the length of array or the number of elements in the array and N denotes the difference between two elements. Second line of each test case contains L space separated integers which denotes the elements of the array.
Output:
For each test case, in a new line print 1 if the pair is found otherwise print -1 if there does not exist any such pair.
Constraints:
1<=T<=100
1<=L<=104
1<=Arr[i]<=105
Example:
Input:
2
6 78
5 20 3 2 5 80
5 45
90 70 20 80 50
Output:
1
-1


SOLUTION:

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,d,flag=0,i;
	    cin>>n>>d;
	    
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    unordered_set<int> s;
	    
	    for(i=0;i<n;i++)
	    {
	        if(s.find(a[i]+d)!=s.end() || s.find(a[i]-d)!=s.end())
	        {
	            flag=1;
	            break;
	        }
	        s.insert(a[i]);
	    }
	    
	    if(flag==0)
	    cout<<-1<<endl;
	    else
	    cout<<1<<endl;
	}
	return 0;
}
