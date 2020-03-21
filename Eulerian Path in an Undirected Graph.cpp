#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,i,j,even=0,odd=0,s;
	    cin>>n;
	    
	    int G[n][n];
	    
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        cin>>G[i][j];
	    }
	    
	    for(i=0;i<n;i++)
	    {   
	        s=0;
	        for(j=0;j<n;j++)
	        {
	            if(G[i][j]==1)
	            s++;
	        }
	        if(s%2==0)
	        even++;
	        else
	        odd++;
	    }
	    
	    if(odd==0 || odd==2)          //given that graph is single component
	    cout<<"1"<<endl;              
	    else
	    cout<<"0"<<endl;
	}
	
	return 0;
}
