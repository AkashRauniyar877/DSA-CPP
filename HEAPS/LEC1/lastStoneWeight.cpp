#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int lastStone(vector<int>&arr){
    priority_queue<int>pq;
    for(int x : arr){
        pq.push(x);
    }
    while(pq.size()>1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        if(x!=y) pq.push(x-y);
    }
    if(pq.size()==1) return pq.top();
    else return 0;
}
int main(){
    vector<int>arr={2,7,4,1,8,1};
    int a = lastStone(arr);
    cout<<a;
  
}