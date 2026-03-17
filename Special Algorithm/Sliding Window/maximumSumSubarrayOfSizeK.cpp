#include<iostream>
using namespace std;

int main(){
    int arr [] = {7,1,2,5,8,4,9,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int maxSum = INT16_MIN;
    int maxIdx = -1;
    for(int i=0;i<=n-k;i++){  // ops= n-k+1
        int sum = 0;
        for(int j=i;j<i+k;j++){  // k times
            sum += arr[j];
        }
       // maxSum = max(maxSum,sum);
       if(maxSum< sum){
        maxSum = sum;
        maxIdx = i;
       }
    }
    // t.C= O(k*n);

     cout<<maxSum<<"\n";
     cout<<maxIdx;
}