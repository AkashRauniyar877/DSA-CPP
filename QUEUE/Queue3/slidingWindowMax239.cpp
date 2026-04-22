#include<iostream>
#include<queue>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k){
    if(k==1) return nums;
    deque<int>dq;
    int n = nums.size();
    vector<int>ans;
    for(int i=0;i<n;i++){
        while(dq.size()>0 && nums[i]>nums[dq.back()]) dq.pop_back();
        dq.push_back(i);
        int j = i-k+1;
        while(dq.front()<j) dq.pop_front();
        if(i>=k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main(){
     // vector<int> nums = {1,3,-1,-3,5,3,6,7};
      vector<int>nums={7,2,4};
     // int k = 3;
     int k = 2;

    vector<int> result = maxSlidingWindow(nums, k);

    for (int x : result) {
        cout << x << " ";
    }


}