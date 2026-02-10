#include<iostream>
#include<vector>
#include<string>
using namespace std;
void storeSubset(string ans, string original,vector<string>&v, bool check ){
    if(original==""){
        v.push_back(ans);
        return;
    }
    char ch = original[0];
    if(original.length()==1){
        if(check){
    storeSubset(ans,original.substr(1),v,true);
            }
            else{
    storeSubset(ans+ch,original.substr(1),v,true);
         }
         char dh = original[1];
         if(ch==dh && check){
             storeSubset(ans,original.substr(1),v,false);
         }
         else{
             storeSubset(ans+ch,original.substr(1),v,true);
         }


    }
}


int main(){
    string s = "aab";
    vector<string>v;
    storeSubset("",s,v,true);
    for(string x:v){
        cout<<x<<" ";
    }
}