#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int>pi;
vector<int> findClosestElements(vector<int>& arr, int k, int x){
    vector<int>ans;
    priority_queue<pi>pq;
    for(int ele : arr ){
        int dis = abs(x-ele);
        pq.push({dis,ele});
        if(pq.size()>k) pq.pop();
    }
    while(pq.size()>0){
        int e = pq.top().second;
        ans.push_back(e);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;


}
int main(){
    vector<int> arr{1,2,3,4,5,6};
    int k = 4;
    int x = 3;
    vector<int>a = findClosestElements(arr,k,x);
    for(auto x: a){
        cout<<x<<" ";
    }
}