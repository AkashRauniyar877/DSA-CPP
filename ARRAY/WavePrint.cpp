#include<iostream>
#include<vector>
using namespace std;

int main (){
 int m,n;
 cout<<"Enter Number of Rows of Matrix:";
 cin>>m;
cout<<"Enter Number of Columns of Matrix:";
 cin>>n;
 int arr[m][n];
 for(int i=0; i<m;i++){
    for(int j=0; j<n;j++){
        cin>>arr[i][j];
    }
 }
 cout<<endl;
//  cout<<"Wave Print"<<endl;
// //Wave print 
// for(int i=0; i<m;i++){
//     if(i%2==0){
//     for(int j=0; j<n;j++){
//         cout<<arr[i][j]<<" ";
//     }
// }
// else{
//      for(int j=n-1; j>=0;j--){
//         cout<<arr[i][j]<<" ";
//     }
// }
//    // cout<<endl;
//  }

    //column wise print
    for(int j =0; j<n;j++){
        for(int i=0; i<m;i++){
            cout<<arr[i][j]<<" ";
        }
    }


}