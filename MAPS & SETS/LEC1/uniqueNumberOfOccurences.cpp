#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
bool uniqueOccurences(vector<int>& arr){
    int n = arr.size();
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    unordered_set<int>s;
    for(auto x : m){
        int freq = x.second;
        if(s.find(freq)!=s.end()){
            return false;
        }
        else s.insert(freq);
    }
    return true;
}
int main(){
    vector<int>arr = {1,2,2,1,1,3};
    if(uniqueOccurences(arr)){
        cout<<"True"<<endl;
    }
    else cout<<"False"<<endl;
}