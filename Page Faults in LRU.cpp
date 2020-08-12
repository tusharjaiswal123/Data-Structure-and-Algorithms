PROBLEM:

In operating systems that use paging for memory management, page replacement algorithm are needed to decide which page needs to be replaced when the new page comes in.
Whenever a new page is referred and is not present in memory, the page fault occurs and Operating System replaces one of the existing pages with a newly needed page.
Given a sequence of pages and memory capacity, your task is to find the number of page faults using Least Recently Used (LRU) Algorithm.
Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains n number of pages and next line contains space seaprated sequence
of pages. The following line consist of the capacity of the memory. 
Note: Pages are referred in the order left to right from the array (i.e index 0 page is referred first then index 1 and so on). Memory is empty at the start.
Output:
Output the number of page faults.
Constraints:
1<=T<=100
1<=n<=1000
4<=capacity<=100
Example:
Input:
2
9
5 0 1 3 2 4 1 0 5
4
8
3 1 0 2 5 4 1 2
4
Output:
8
7


SOLUTION:

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,k,i,c=0;
	    cin>>n;
	    
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    cin>>k;
	    
	    list<int> q;
	    unordered_set<int> s;
	    
	    for(i=0;i<n;i++)
	    {   
	        if(q.size()<k)                      //if some memory field is empty
	        {
	            if(s.find(a[i])==s.end())       //Miss
	            {
	                c++;                           
	                s.insert(a[i]);
	                q.push_back(a[i]);
	            }
	            else
	            {
	                q.remove(a[i]);
	                q.push_back(a[i]);
	            }
	        }
	        else
	        {
	            if(s.find(a[i])==s.end())
	            {    
	                s.erase(q.front());
	                q.pop_front();
	                q.push_back(a[i]);
	                c++;
	                s.insert(a[i]);
	            }
	            else
	            {
	                q.remove(a[i]);
	                q.push_back(a[i]);
	            }
	        }
	    }
	    
	    cout<<c<<endl;
	    
	}
	return 0;
}
