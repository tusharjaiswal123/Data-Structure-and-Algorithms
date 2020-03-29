void bubbleSort(int arr[], int n)    //Swap adjacent elements if a[j] > a[j+1]   
{   int i,j;                         //Repeat this n times  O(n^2)
                                     //We can optimize bubble sort so best case time complexity O(n)
    for(i=0;i<n-1;i++)
    {
      for(j=0;j<n-i-1;j++)
      {
        if(arr[j]>arr[j+1])
        swap(&arr[j],&arr[j+1]);
      }
    }
}
