void heapify(int a[],int n,int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int max=i;
    
    if(l<n && a[l]>a[max])
    max=l;
    
    if(r<n && a[r]>a[max])
    max=r;
    
    if(max!=i)
    { 
       swap(a[i],a[max]);
       
       heapify(a,n,max);
    }
}

void HeapSort(int a[],int n)    //O(nlogn)
{ 
    int i;
    
    for(i=(n/2)-1;i>=0;i--)   //Build max heap
    heapify(a,n,i);           
    
    for(i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        
        heapify(a,i,0);
    }
}
