#include<iostream>
#include<vector>
using namespace std;

void printMax(int arr[], int n, int idx, int maxSoFar){
    if(idx == n) {
        cout<<maxSoFar;
        return;
    }
    if(arr[idx]>maxSoFar) maxSoFar = arr[idx];
    printMax(arr,n,idx+1,maxSoFar);

}
int maxInArray(int arr[], int n, int idx){
    if(idx == n-1) return arr[idx];
    int maxInRest = maxInArray(arr,n,idx+1);
    return max(arr[idx],maxInRest);

}


int main(){
    int arr[] = {1,2,3,4,5,97,78,56,45,23};
    int n = sizeof(arr)/sizeof(int);
  printMax(arr,n,0,INT8_MIN);
  cout<<maxInArray(arr,n,0);
   
}