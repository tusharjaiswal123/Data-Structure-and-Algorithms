PROBLEM:

Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item.
Input:
First line consists of an integer T denoting the number of test cases. First line consists of two integers N and W, denoting number of items and weight respectively. Second
line of every test case consists of 2*N spaced integers denoting Values and weight respectively. (Value1 Weight1 Value2 Weight2.... ValueN WeightN)
Output:
Print the maximum value possible to put items in a knapsack, upto 2 decimal place.
Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= W <= 100
Example:
Input:
2
3 50
60 10 100 20 120 30
2 50
60 10 100 20
Output:
240.00
160.00


SOLUTION:

#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int> a,const pair<int,int> b)
{
    return (a.first*b.second) > (b.first*a.second);
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,w,i,a,b;
	    double c=0;
	    cin>>n>>w;
	    
	    vector<pair<int,int>> v;
	    

	    for(i=0;i<n;i++)
	    {   
	        cin>>a>>b;
	        v.push_back({a,b});
	    }
	    
	    
	    sort(v.begin(),v.end(),cmp);
	    

	    
	   for(i=0;i<n;i++)
	    {
	        if(v[i].second<=w)
	        {
	            c+=v[i].first;
	            w=w-v[i].second;
	        }
	        else if(w<v[i].second)
	        {
	            c+= w*((double)v[i].first/(double)v[i].second);
	            w=0;
	            break;
	        }
	        
	    }
	    
	    cout<<fixed<<setprecision(2)<<(double)c<<endl;
	    
	}
	return 0;
}
