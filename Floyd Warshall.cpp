#include <iostream>
using namespace std;

int main() {
	
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,i,j,k;
        cin>>n;
        
        int a[n][n];
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {   
                        a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                }
            }
        }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]==10000000)
                cout<<"INF ";
                else
                cout<<a[i][j]<<" ";
            }
            
            cout<<endl;
        }
    }
	return 0;
}
