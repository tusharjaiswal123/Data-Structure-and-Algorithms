typedef pair<int,int> pi;
int *mergeKArrays(int arr[][N], int k)
{
    
    priority_queue<pi,vector<pi>,greater<pi>> q;
    int i,j;
    int *a=new int[k*k];
    int n[k]={0};
    
    j=0;
    
    for(i=0;i<k;i++)
    {
        q.push({arr[i][0],i});
    }
    
    for(i=0;i<k*k;i++)
    {
        pair<int,int> p=q.top();
        q.pop();
        a[j]=p.first;
        j++;
        
        if(n[p.second]<k-1)
        {
            ++n[p.second];
            q.push({arr[p.second][n[p.second]],p.second});
        }
    }
    
    return a;
}






#include<bits/stdc++.h>
using namespace std;

int main() {

	int n,k,i,j;
	cin>>k>>n;

	int a[k][n];

	priority_queue< pair<int, pair<int,int> >,vector< pair<int, pair<int,int> > >,
	greater< pair<int, pair<int,int> > > > pq;
	vector<int> ans;

	for(i=0;i<k;i++)
	{
		for(j=0;j<n;j++)
		cin>>a[i][j];
	}

	for(i=0;i<k;i++)
	{	
		pq.push({a[i][0],{i,0}});
	}

	while(!pq.empty())
	{
		auto p=pq.top();
		pq.pop();

		ans.push_back(p.first);

		if(p.second.second+1<n)
		{
			pq.push({a[p.second.first][p.second.second+1],{p.second.first,p.second.second+1}});
		}
	}

	for(auto s:ans)
	cout<<s<<" ";

	cout<<endl;

	return 0;
}
