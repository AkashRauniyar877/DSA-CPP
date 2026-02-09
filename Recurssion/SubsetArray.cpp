#include<iostream>
#include<vector>
using namespace std;
void printSubset(int arr[], int n, int idx, vector<int> ans){
    if(idx == n) {
        for(int num: ans) cout<<num<<" ";
        cout<<endl;
        return;
    }
    ans.push_back(arr[idx]);
    printSubset(arr,n,idx+1,ans);
    ans.pop_back();
    printSubset(arr,n,idx+1,ans);

}


int main(){
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(int);
    vector<int> ans;
    printSubset(arr,n,0,ans);



}