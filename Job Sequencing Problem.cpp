PROBLEM:

Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.
Input:
The first line of input contains an integer T denoting the number of test cases. Each test case consist of an integer N in first line denoting the number of jobs and the next line consist of Job id, Deadline and the Profit associated to that Job.
Output:
Output the number of jobs done and the maximum profit.
Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= Deadline <= 100
1 <= Profit <= 500
Example:
Input:
2
4
1 4 20 2 1 10 3 1 40 4 1 30
5
1 2 100 2 1 19 3 2 27 4 1 25 5 1 15
Output:
2 60
2 127


SOLUTION:

#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,a,c=0,s=0;
	    cin>>n;
	    
	    vector<pair<int,int>> v(n);
	    
	    for(i=0;i<n;i++)
	    {
	        cin>>a;
	        cin>>v[i].second>>v[i].first;
	    }
	    
	    sort(v.begin(),v.end(),greater<pair<int,int>>());
	    int vis[101]={0};
	    
	    
	    for(i=0;i<n;i++)
	    {
	        for(int j=v[i].second;j>=1;j--)
	        {
	            if(vis[j]==0)
	            {
	                vis[j]=1;
	                c++;
	                s+=v[i].first;
	                break;
	            }
	        }
	    }
	    
	    cout<<c<<" "<<s<<endl;
	    
	}
	return 0;
}
