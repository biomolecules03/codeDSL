
//Ankit Gyandev More
// roll no.7209
// SE COMP B
#include <bits/stdc++.h>
using namespace std;
int iter = 0;

//linear search
void linear_search(int arr[], int size , int x)
{
        int cnt = 0;
        bool flg = false;
        for(int i=0;i<size;i++)
        {
                if(x == arr[i])
                {                     
                        cnt ++;
                        flg = false;
                        break;
                } 
                else 
                {
                        flg = true;
                        cnt ++;
                }
        }
        
        if (flg == true)
        {
                cout<<"Searched student did not attended program (using linear search) ";
        }
        
        else
        {
                cout<<"Searched student attended the program,found with total iterations (using linear search) : "<<cnt<<endl;
                
        }
}

//sentinel search
void sentinel_search(int arr[], int size , int key)
{
        int arr1[size+1];
        for(int i = 0 ; i<size ; i++){
                arr1[i] = arr[i];
        } 
        arr1[size] = key;
        
        bool flg = true;
        
        for(int j = 0 ; j < size + 1 ; j++){
                if ( j < size){
                        if( arr1[j] == key){
                                cout<<"Searched student attended the program, found at index (using sentinel search) "<<j<<endl;
                                flg=true;
                                break;
                        }
                        else
                        {
                                flg = false;
                        }
                }        
        }
        if (flg == false){
                cout<<"Searched student did not attended program (using sentinel search) "<<endl;
        }   
}

int main()
{   
        int n;
        cout<<"Enter number of elements of the array : ";
        cin>> n;
        
        int arr[n];
        cout<<"Enter the elements of array : ";
        for(int i=0;i<n;i++){
                cin>>arr[i];
        }
        
        int x;
        cout<<"Enter the element to search in the array : ";
        cin>>x;

        linear_search(arr,n,x);
        sentinel_search(arr, n , x);
        
        return 0;     
}



