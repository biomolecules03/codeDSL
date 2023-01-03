// Ankit Gyandev More
// Roll No.
// SE COMP B
#include <bits/stdc++.h>
using namespace std;

// Radix sort

void radix_sort(int size, int array[])
{
	int x, arr_max=0;
	int length=1;

  int arr[size];
  queue<int> q[10];
  for(int i = 0; i < size ; i++)
    {
      arr[i] = array[i];
      q[arr[i]%10].push(arr[i]);
      if (arr[i] > arr_max)
      { arr_max = arr[i];}
    }

	while (arr_max>0) 
	{arr_max/=10; length++; }

	int d =10;
	while(length--){
		int n=0;

		for (int i=0; i<10; i++){
			
			while(!q[i].empty())
			{		
				arr[n] =q[i].front();
				q[i].pop(); n++;
			}
		}
		
		for (int i=0; i<size; i++)
		{
			int r=arr[i]; 
			cout << arr[i] << " ";
			q[(r/d)%10].push(arr[i]);
		}
		d*=10;
		cout << endl;
	}
}


int main()
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
    cout<<"**RADIX SORT**"<<endl;
    radix_sort(n, arr);

    return 0;
}

