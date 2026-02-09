#include<iostream>
#include<string>
using namespace std;
// void removeChar(string ans, string original){
//     if(original.length() == 0){
//         cout<<ans;
//         return;
//     }
//     char ch = original[0];
//     if(ch=='a')removeChar(ans,original.substr(1));
//     else removeChar(ans+ch,original.substr(1));

// }

void removeChar(string ans, string original, int idx){
    if(idx == original.length()){
        cout<<ans;
        return;
    }
    char ch = original[idx];
    if(ch=='a')removeChar(ans,original,idx+1);
    else removeChar(ans+ch,original,idx+1);

}


int main (){
    string str = "Akash Rauniyar";
    // string s = "";
    // int n = str.length();
    // for(int i=0;i<n;i++){
    //     if(str[i] == 'a') continue;
    //     s += str[i];
    // }
    // cout<<s;

  //  removeChar("",str);
    removeChar("",str,0);

}