#include<iostream>
#include<stack>
#include<string>
#include <algorithm>
using namespace std;
int main(){
    int arr[] = {100,80,60,81,70,60,75,85};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // pop ans push
    stack<int> st;
    int pgi[n];
    pgi[0] = 1;
    st.push(0); 
    for(int i=1;i<n;i++){
        //pop all the elemnts smaller than arr[i]
        while(st.size()>0 && arr[st.top()]<=arr[i]){
            st.pop();
        }
        // mark the ans in nge array
        if(st.size()==0) pgi[i] = -1;
        else pgi[i] = st.top();
        pgi[i] = i- pgi[i];
        //pushh the arr[i]
        st.push(i);
    }
     
    for(int i=0;i<n;i++){
        cout<<pgi[i]<<" ";
    }
  

}
   