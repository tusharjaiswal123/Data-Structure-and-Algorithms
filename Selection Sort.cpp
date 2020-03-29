void selectsort(int arr[], int n)
{
    int i,j;                      // select maximum element and swap it with last position element
                                  //Time complexity O(n^2) in all cases
    for(i=n-1;i>=0;i++)
    {   
        int mx=-1,ans;
        for(j=0;j<=i;j++)
        {
          if(arr[j]>mx)
          {
             mx=arr[j];
             ans=j;
          }
          swap(&a[i],&a[ans]);
        }
    }    
    
}
