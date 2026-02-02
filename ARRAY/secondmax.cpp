#include<iostream> 
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i =0 ; i<n; i++){
        cin>> arr[i];
    }

    int max = INT8_MIN;
    for(int i =0; i<n; i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int secmax = INT8_MIN;
    for(int i =0; i<n; i++){
        if(arr[i]>secmax && arr[i]<max){
            secmax=arr[i];
        }
    }
    cout<<"The largest element in the array is: "<<max<<endl;
    cout<<"The second largest element in the array is: "<<secmax;

}