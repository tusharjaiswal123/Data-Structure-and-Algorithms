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
