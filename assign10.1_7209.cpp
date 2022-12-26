// Ankit Gyandev More
// Roll No.
// SE COMP B
#include <bits/stdc++.h>
using namespace std;

// Quick sort

void quicksort(int arr[],int start,int end,int n)
{
  int i=start+1,j=end;
  if(i<=j)
  {
      int pivot=arr[start];
      while(i<j)
  {
      while(arr[i]<=pivot && i<end)
        i++;
      while(arr[j]>=pivot && j>start)
        j--;
      if(i<j) swap(arr[i],arr[j]);
      else break;
  }
  if(i>=j)
  { 
      if(arr[j]<arr[start])
      swap(arr[j],arr[start]);
  } 

  for(int i=0;i<n;i++)
  {cout<<arr[i]<<" ";}
  cout<<endl; 
    
  quicksort(arr,j+1,end,n);
  quicksort(arr,start,j-1,n);
  }
}


int  main()
{
    int n;
    cout<<"enter the total number of students : ";
    cin>>n;
    int arr[n];
    cout<<"enter percentage marks of students : ";
    for(int i = 0; i < n ; i++)
    {
      cin>>arr[i];
    }
    cout<<endl;
    
    int start=0, end=n-1; 
    cout<<"**QUICK SORT**"<<endl;
    quicksort(arr,start,end,n);
    
    return 0;
}