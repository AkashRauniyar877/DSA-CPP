#include<iostream>
using namespace std;
int main(){
    int arr[6]={5,4,6,1,3,2};
    int n = 6;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

   // Insertion Sort
    for(int i=1;i<n;i++){
          int current = arr[i];
          int j = i-1;
          while(arr[j]>current && j>=0){
                arr[j+1] = arr[j];
                j--;
          }
          arr[j+1] = current;
    }

    // another approach
    // for(int i=1;i<n;i++){
    //     int j = i;
    //     while(j>=1){
    //         if(arr[j]>=arr[j-1]){
    //             break;
    //         }
    //         else{
    //             swap(arr[j],arr[j-1]);
    //         }
    //         j--;
    //     }
    // }
    
     for(int i=0;i<n;i++){
          cout<<arr[i]<<" ";
     }
}