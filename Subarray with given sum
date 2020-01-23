#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,sum,i,flag=0;
	    cin>>n>>sum;
	    
	    int a[n];
	    
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    
	    int curr_sum=a[0],j=0;
	    
	    for(i=1;i<=n;i++)
	    {
	        
	        while(curr_sum>sum && j<i-1)
	        {
	            curr_sum=curr_sum-a[j];
	            j++;
	        }
	        
	        if(curr_sum==sum)
	        {
	            flag=1;
	            break;
	        }
	        if(i<n)
	        curr_sum += a[i];
	    }
	    if(flag==0)
	    cout<<-1<<endl;
	    else
	    cout<<j+1<<" "<<i<<endl;
	}
	return 0;
}
