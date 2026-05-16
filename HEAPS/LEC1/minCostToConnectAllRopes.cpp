#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    vector<int>arr={2,7,4,1,8};
    priority_queue<int,vector<int>,greater<int>>p;
    for(int x : arr){
        p.push(x);
    }
    int cost = 0;
    while(p.size()>1){
        int x = p.top();
        p.pop();
        int y = p.top();
        p.pop();
        cost += x+y;
        p.push(x+y);
    }

    cout<<cost;
  
}