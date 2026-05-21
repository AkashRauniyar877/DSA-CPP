#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target){
   unordered_map<int,int>m;
   vector<int>ans;
   for(int i=0;i<nums.size();i++){
    int rem = target - nums[i];
    if(m.find(rem)!=m.end()){
        ans.push_back(m[rem]);
        ans.push_back(i);
    }
    else m[nums[i]] = i;
   }
   return ans;
}

int main(){
    vector<int>nums = {2,7,11,15};
    int target = 9;
    vector<int>ans = twoSum(nums,target);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}