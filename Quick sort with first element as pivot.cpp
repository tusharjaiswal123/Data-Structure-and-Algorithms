#include <iostream>
using namespace std;

void QuickSort(int A[],int low,int high)
{   
    int k=high-low+1;
    if(k>=2)
    {
        int pivot=A[low];
        int lb=low;
        int ub=high;
        while(lb<=ub)
        {
            while(A[lb]<=pivot && lb<=high)
            lb++;
            
            while(A[ub]>pivot && ub>=low)
            ub--;
            
            if(lb<=ub)
            swap(A[lb],A[ub]);
        }
        swap(A[low],A[ub]);
        QuickSort(A,low,ub-1);
        QuickSort(A,ub+1,high);
        
    }
}


int main()
{   
    int n,i;
    cout<<"Enter the size of Array"<<endl;
    cin>>n;
    
    int A[n];
    
    for(i=0;i<n;i++)
    cin>>A[i];
    
    QuickSort(A,0,n-1);
    
    cout<<"Array after applying QuickSort Algorithm"<<endl;
    
    for(i=0;i<n;i++)
    cout<<A[i]<<" ";

    return 0;
}
