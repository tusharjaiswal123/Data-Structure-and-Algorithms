#include<iostream>
using namespace std;

int main()
{
    int n,i,j,temp;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int a[n];

    cout<<"Enter the elements of array"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0&&a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }

    cout<<"Sorted array is :"<<" ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
