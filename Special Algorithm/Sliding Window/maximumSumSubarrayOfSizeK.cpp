#include<iostream>
using namespace std;

int main(){
    int arr [] = {7,1,2,5,8,4,9,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    int maxSum = INT16_MIN;
    // int maxIdx = -1;
    // for(int i=0;i<=n-k;i++){  // ops= n-k+1
    //     int sum = 0;
    //     for(int j=i;j<i+k;j++){  // k times
    //         sum += arr[j];
    //     }
    //    // maxSum = max(maxSum,sum);
    //    if(maxSum< sum){
    //     maxSum = sum;
    //     maxIdx = i;
    //    }
    // }
    // // t.C= O(k*n);

    //sliding window
    int maxIdx = 0;
    int prevSum = 0;
    for(int i=0;i<k;i++){
        prevSum += arr[i];
    }
    maxSum = prevSum;
    int i = 1;
    int j = k;
    while(j<n){
        int currSum = prevSum + arr[j] - arr[i-1];
        if(maxSum < currSum){
            maxSum = currSum;
            maxIdx = i;
        }
        prevSum = currSum;
        i++;
        j++;
    }

     cout<<maxSum<<"\n";
     cout<<maxIdx;
}