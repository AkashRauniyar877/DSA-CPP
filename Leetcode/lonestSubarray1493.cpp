#include<iostream>
#include<vector>
using namespace std;
int longestSubarray(vector<int>& nums, int k) {
 int n = nums.size();
        int flips = 0, i=0 , j =0;
        int maxLen = INT16_MIN, len = INT16_MIN;
        while(j<n){
            if(nums[j]==1) j++;
            else{
                if(flips<k){
                    flips++;
                    j++;
                }
                else{
                    len = j-i;
                    maxLen = max(maxLen,len);
                    while(nums[i]==1) i++;
                    i++;
                    j++;
                }
            }
        }
           len = j-i;
            maxLen = max(maxLen,len);
          return maxLen;
}


int main(){
    vector<int> nums = {1,1,1};
    int k = 0;
    cout<<longestSubarray(nums,k)<<endl;
}