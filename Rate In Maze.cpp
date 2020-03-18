#include <bits/stdc++.h>
using namespace std;

	int c=0;

void maze(vector<vector<int>>& a,vector<vector<int>>& sol,int n,int x,int y)
{   
    if(x==n-1 && y==n-1)
    {
        sol[x][y]=1;
        c++;
        cout<<"SOLUTION:"<<endl;   //Printing All possible paths
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        
        return;
    }
    if(x>=n || x<0 || y>=n || y<0 || sol[x][y]==1 || a[x][y]==1)
    return;
    
    sol[x][y]=1;
    maze(a,sol,n,x-1,y);
    maze(a,sol,n,x,y-1);
    maze(a,sol,n,x+1,y);
    maze(a,sol,n,x,y+1);
    
    sol[x][y]=0;
}

int main() {
	int n,i,j;
	cin>>n;
	
	vector<vector<int>> a(n,vector<int>(n,0));
	
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
	    {
	        cin>>a[i][j];
	    }
	}
	
	
	vector<vector<int>> sol(n,vector<int>(n,0));
	

	maze(a,sol,n,0,0);
	cout<<c<<endl;
	
	
	return 0;
}
