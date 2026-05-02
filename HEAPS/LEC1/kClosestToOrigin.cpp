#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,vector<int>>pi;
vector<vector<int>> KClosest( vector<vector<int>> & arr, int k){
    vector<vector<int>>ans;
    priority_queue<pi> pq;
    for(auto v : arr){
        int x = v[0];
        int y = v[1];
        int dis = x*x + y*y;
        pq.push({dis,v});
        if(pq.size()>k) pq.pop();
    }
    while(pq.size()>0){
        vector<int> v = pq.top().second;
        ans.push_back(v);
        pq.pop();
    }
    return ans;
  

}
int main(){
    vector<vector<int>> arr={{3,3},{5,-1},{-2,4}};
    int k = 2;
    vector<vector<int>> a = KClosest(arr,k);
    for(auto row : a){
        for(auto val : row){
            cout << val << " ";
        }
    cout<<endl;
    }
}