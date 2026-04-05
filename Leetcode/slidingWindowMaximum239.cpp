#include<iostream>
#include<stack>
#include<vector>
#include<limits>
#include <algorithm>
using namespace std;
 vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    if(k==1) return arr;
        int n = arr.size();
        stack<int> st;
        int ngi[n];
        ngi[n-1] = n;
        st.push(n-1); 
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.size()==0) ngi[i] = n;
            else ngi[i] = st.top();
            st.push(i);
        }
        vector<int>ans;
        int j = 0;
        for(int i =0;i<n-k+1;i++){
            if(j<i) j=i;
            int mx = arr[j]; // starting
            while(j< i+k){
                mx = arr[j];
                if(ngi[j] >= i+k) break; 
                j = ngi[j];
            }
            
            ans.push_back(mx);
        }
        return ans;
      
    }
    int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7}; 
    int k = 3;  
    vector<int> result = maxSlidingWindow(arr, k);
    cout << "Sliding Window Maximum: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
