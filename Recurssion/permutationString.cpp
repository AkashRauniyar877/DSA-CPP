#include<iostream>
#include<vector>
#include<string>
using namespace std;
void permutation(string ans, string original){
    if(original==""){
        cout<<ans<<" ";
        return;
    }
    for(int i=0;i<original.length();i++){
        char ch = original[i];
        string left = original.substr(0,i);
        string right = original.substr(i+1);
        string newString = left+right;
        permutation(ans+ch,newString);
    }
}


int main(){
    string s = "abc";
  permutation("",s);
}