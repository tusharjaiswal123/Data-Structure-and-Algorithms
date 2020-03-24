PROBLEM:

Given two unsorted arrays arr1[] and arr2[]. They may contain duplicates. For each element in arr1[] count elements less than or equal to it in array arr2[].
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two integers m and n denoting the size of the two arrays. The following two lines will contain both the arrays respectively.

Output:
Print the count of elements less than or equal to it in arr2 for each element in arr1.
Constraints:
1<=T<=100
1<=m,n<=10^5
1<=arr1[i],arr2[j]<=10^5
Example:
Input:
2
6 6
1 2 3 4 7 9
0 1 2 1 1 4
5 7
4 8 7 5 1
4 48 3 0 1 1 5

Output:
4 5 5 6 6 6 
5 6 6 6 3


SOLUTION:

int binary_search(int arr2[],int n,int x,int l,int h)
{
    while(l<=h)
    {   
        int mid=l+(h-l)/2;
        
        if(arr2[mid]==x)
        l=mid+1;
        
        else if(arr2[mid]<x)
        l=mid+1;
        
        else
        h=mid-1;
    }
    return l;
}

void countEleLessThanOrEqual(int arr1[], int arr2[], 
                             int m, int n)
{
    sort(arr2,arr2+n);
    int i;
    
    for(i=0;i<m;i++)
    {
        int p=binary_search(arr2,n,arr1[i],0,n-1);
        
        cout<<p<<" ";
    }
}
