// Ankit Gyandev More          
// 7258            
// SE COMP B
#include <bits/stdc++.h>
using namespace std;
int iter_binary = 0;
int iter_fibo = 0;

//fibonacci search
void fibo_search(int arr[] , int size , int key)
{
        int arr1[size +1];
        for(int i = 1 ; i<size + 1 ; i++){
                arr1[i] = arr[i-1];
        } 
        
        int m2 = 0;
        int m1 = 1;
        int m = 0;

        while(m<size){             
                m2 = m1;
                m1 = m;
                m = m1 + m2;
        }
        
        int offset = 0;
        int i = 0;
        int cnt=0;
        while(m > 1)
        {
                iter_fibo++;
                i = min(offset + m2 , size);
                
                if (arr1[i] < key)
                {
                        offset = i;
                        m = m1;
                        m1 = m2;
                        m2 = m - m1;
                }
                
                else if (arr1[i] > key)
                {
                        m = m2;
                        m1 = m1 - m;
                        m2 = m - m1;                  
                }
                  
                else
                {
                        cnt++;
                        break;
                 }                                
        }

        if(cnt==0) 
        {
        cout<<"Searched student did not attend program (using fibo search) "<<endl;
        }       
        else
        {
               cout<<"Searched student attended program, found (using fibonacci search) at index "<<i<<" with total iterations : "<<iter_fibo<<endl; 
        }
}

int binary_search(int arr[],int size, int element)
{
        sort(arr,arr+size);
        int left = 0;
        int right = size -1;
        int mid ;
        while(left<=right)
        {
                iter_binary++;
                mid = (left + right)/2;
                if (arr[mid] == element)
                {                     
                        return mid;
                }
                else if (arr[mid] < element)
                        {
                                left = mid + 1 ;
                         }
                else
                {
                        right = mid -1 ;
                }             
        }   
        return -1;
}

int main()
{
        int n;
        cout<<"Enter number of elements of the array : ";
        cin>> n;
        
        int arr[n];
        cout<<"Enter the elements of array : ";
        for(int i=0;i<n;i++)
        {
                cin>>arr[i];
        }
        
        int x;
        cout<<"Enter the element to search in the array : ";
        cin>>x;

        fibo_search(arr , n , x);     

        int bs = binary_search(arr,n,x);
        if (bs == -1)
        {
                cout<<"Searched student did not attended program (using binary search"<<endl;
        }
        else
        {
                cout<<"Searched student attended program, found (using binary search) at index "<<bs<<" with total iterations : "<<iter_binary<<endl;
        }
           
        return 0;
}

