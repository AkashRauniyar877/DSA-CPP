#include<iostream>
#include<queue>
using namespace std;

int main(){
    int arr [] = {3,-4,-7,2,5,-9,5,65,32,-1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    vector<int>ans;
    queue<int>q;
    for(int i=0;i<n;i++){
        if(arr[i]<0) q.push(i);
    }
    int i = 0;
    while(i<=n-k){
        while(q.size()>0 && q.front()<i ) q.pop();
        if(q.size()==0 || q.front()>=i+k) ans.push_back(0);
        else ans.push_back(arr[q.front()]);
        i++;
         
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    


}