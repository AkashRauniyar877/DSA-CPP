#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int kthLargestElememt(vector<int>& arr, int k){
    int n = arr.size();
    priority_queue<int,vector<int>,greater<int>>hp;
    for(int i=0;i<n;i++){
        hp.push(arr[i]);
        if(hp.size()>k) hp.pop();
    }
    return hp.top();
}
int main(){
    vector<int> arr = {10,20,-4,6,18,24,105,118};
    int k = 3;
    cout<<kthLargestElememt(arr,k);
}