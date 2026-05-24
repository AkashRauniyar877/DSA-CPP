#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int reverse(int n){
    int r = 0;
    while(n>0){
        r *= 10;
        r += (n%10);
        n /= 10;
    }
    return r;
}
int countDistinctInteger(vector<int>&nums){
    int n = nums.size();
    for(int i=0;i<n;i++){
        int rev = reverse(nums[i]);
        nums.push_back(rev);
    }
    unordered_set<int>s;
    for(int i=0;i<nums.size();i++){
        s.insert(nums[i]);

    }
    return s.size();
}

int main(){
    vector<int>nums = {1,13,10,12,31};
    cout<<countDistinctInteger(nums)<<endl;
}