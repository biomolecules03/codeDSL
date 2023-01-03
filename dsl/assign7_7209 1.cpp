//Ankit Gyandev More
// 7209
// SE COMP B 
#include <iostream>
using namespace std;

int main (){
        //1st matrix
        int r1;
        int c1;
        cout<<"Enter number of rows and column for 1st matrix : ";
        cin>>r1>>c1;
        int a[r1][c1];
        int cnt1=0;
        cout<<"Enter entries : ";
        for(int i = 0 ; i<r1 ; i++)
        {
                for(int j = 0 ; j<c1 ; j++)
                {
                        cin>>a[i][j]; 
                        if(a[i][j]!=0)cnt1++;             
                }
        }
         //2nd matrix   
       
        int r2;
        int c2;
        cout<<"Enter number of rows and column for 2nd matrix: ";
        cin>>r2>>c2;
        int b[r2][c2];
        int cnt2=0;
        cout<<"Enter entries : ";
        for(int i = 0 ; i<r2 ; i++){
           for(int j = 0 ; j<c2 ; j++){
                cin>>b[i][j]; 
                if(b[i][j]!=0)cnt2++;             
           }
        }
      //   Making Sparse
        int v[cnt1+1][3];
        v[0][0]=r1;
        v[0][1]=c1;
        v[0][2]=cnt1;
        int k=1;
        for(int i = 0 ; i<r1 ; i++)
        {
                for(int j = 0 ; j<c1 ; j++)
                {
                           if(a[i][j] != 0)
                           {
                                v[k][0] = i; 
                                v[k][1] = j;
                                v[k][2] = a[i][j];
                                k++;
                           }       
                }
        }
       

        int V[cnt2+1][3];
        V[0][0]=r2;
        V[0][1]=c2;
        V[0][2]=cnt2;
        int l=1;
        for(int i = 0 ; i<r2 ; i++){
           for(int j = 0 ; j<c2 ; j++){
              if(b[i][j] != 0){
                V[l][0] = i; 
                V[l][1] = j;
                V[l][2] = b[i][j];
                l++;
              }       
           }
        }
        
        cout<<"1st matrix"<<endl;
        for(int i=0;i<=cnt1;i++){
         for(int j=0;j<3;j++){
           cout<<v[i][j];
         }
        cout<<endl;
        }
        cout<<"2nd matrix"<<endl;
        for(int i=0;i<=cnt2;i++){
          for(int j=0;j<3;j++){
           cout<<V[i][j];
          }
        cout<<endl;
        }
        
        cout<<endl;
         //addition

        int ans[(v[0][2] + V[0][2] + 1)][3];
        if(v[0][0] == V[0][0] and v[0][1] == V[0][1]){
        ans[0][0] = v[0][0];
        ans[0][1] = v[0][1];
        int i = 1;
        int j = 1;
        int k = 1;
        while(i<v[0][2]+1 and j<V[0][2]+1 ){
            if(v[i][0] == V[j][0] and v[i][1] == V[j][1]){
                ans[k][2] = v[i][2] + V[j][2];
                ans[k][0] = v[i][0];
                ans[k][1] = v[i][1];
                i++;
                j++;
                k++;      
            }
            else if (v[i][0] == V[j][0] and v[i][1] < V[j][1]){
                ans[k][0] = v[i][0];
                ans[k][1] = v[i][1];
                ans[k][2] = v[i][2];
                i++;
                k++; 
            }
            else if(v[i][0] == V[j][0] and v[i][1] > V[j][1]){
                ans[k][0] = V[j][0];
                ans[k][1] = V[j][1];
                ans[k][2] = V[j][2];
                k++;
                j++; 
            }
            else{
                if(v[i][0] < V[j][0]){
                    ans[k][0] = v[i][0];
                    ans[k][1] = v[i][1];
                    ans[k][2] = v[i][2];
                    k++;
                    i++; 
                }
                else{
                    ans[k][0] = V[j][0];
                    ans[k][1] = V[j][1];
                    ans[k][2] = V[j][2];
                    k++;
                    j++;
                }
              }
        }       
        while(i<=v[0][2]){
            ans[k][0] = v[i][0];
            ans[k][1] = v[i][1];
            ans[k][2] = v[i][2];
            k++;
            i++;
        }
        while(j<=V[0][2]){
            ans[k][0] = V[j][0];
            ans[k][1] = V[j][1];
            ans[k][2] = V[j][2];
            k++;
            j++;
        }
        ans[0][2] = k - 1;
        }
        else{
        cout<<"Order of both matrices are not same";
        }
        cout<<"Addition is "<<endl;
        for (int i = 0;i<ans[0][2]+1;i++){
            for (int j = 0; j<3; j++){
                    cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }  
        cout<<endl;
        // simple transpose
        
        int c[v[0][2] + 1][3];
        c[0][0] = v[0][1];
        c[0][1] = v[0][0];
        c[0][2] = v[0][2];
        k= 1;
        for(int j = 0; j <c[0][1]; j++){
            for(int i = 0 ; i <= c[0][2] ; i++){
                if (v[i][1] == j){
                        c[k][0] = v[i][1];
                        c[k][1] = v[i][0];
                        c[k][2] = v[i][2];
                        k++;
                }
            }       
        }
        
        cout<<"Simple transpose is "<<endl;
        for (int i = 0;i<c[0][2]+1;i++){
            for (int j = 0; j<3; j++){
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }  
        cout<<endl;
       
       //fast transpose
       
       int A1[v[0][1]]={0};
       for (int i = 1 ; i<=v[0][2] ; i++){
            A1[v[i][1]]++;
       }
       int A2[v[0][1]]={0};
       A2[0] = 1;
       for(int i = 1 ; i<v[0][1] ; i++){
                A2[i] = A1[i-1] + A2[i-1];
       }
       int ans1[v[0][2] + 1][3]={0};
       ans1[0][0] = v[0][1];
       ans1[0][1] = v[0][0];
       ans1[0][2] = v[0][2];
       
       for(int i = 1; i<= v[0][2]; i++){
            ans1[A2[v[i][1]]][0] = v[i][1];
            ans1[A2[v[i][1]]][1] = v[i][0];
            ans1[A2[v[i][1]]][2] = v[i][2];
            A2[v[i][1]]++;
       }
       
       cout<<"Fast transpose is "<<endl;
       for (int i = 0;i<ans1[0][2]+1;i++){
            for (int j = 0; j<3; j++) {
                cout<<ans1[i][j]<<" ";
            }
            cout<<endl;
        }  
        cout<<endl;
        return 0;
}