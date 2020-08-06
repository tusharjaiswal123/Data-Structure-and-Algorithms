#include<iostream>
using namespace std;


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


int partition_r(int arr[], int low, int high)   //Randomized Quicksort
{ 
    // Generate a random number in between 
    // low .. high 
    srand(time(NULL)); 
    int random = low + rand() % (high - low); 
  
    // Swap A[random] with A[high] 
    swap(arr[random], arr[high]); 
  
    return partition(arr, low, high); 
} 


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array:"<<endl;
    printArray(arr, n);
    return 0;
}





Randomized QuickSort:




#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 

int partition(int a[],int n,int l,int h)
{
	int pivot=a[h];
	int i=l-1;

	for(int j=l;j<h;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[h],a[i+1]);
	return i+1;
}

int partition_random(int a[],int n,int l,int h)
{
	srand(time(NULL));
	int random = l+rand()%(h-l);

	swap(a[random],a[h]);

	return partition(a,n,l,h);
}

void quickSort(int a[],int n,int l,int h)
{
	if(l<h)
	{
		int p=partition_random(a,n,l,h);

		quickSort(a,n,l,p-1);
		quickSort(a,n,p+1,h);
	}
}

int main()
{   
    int n,i;
	cin>>n;

	int a[n];

	for(i=0;i<n;i++)
	cin>>a[i];

	quickSort(a,n,0,n-1);

	for(i=0;i<n;i++)
	cout<<a[i]<<" ";

	cout<<endl;

    return 0;
}

