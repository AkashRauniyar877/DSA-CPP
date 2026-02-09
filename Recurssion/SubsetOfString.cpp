#include<iostream>
#include<vector>
using namespace std;
// void printSubset(string ans, string original ){
//     if(original.length() == 0){
//         cout<<ans<<endl;
//         return;
//     }
//     char ch = original[0];
//     string ros = original.substr(1);
//     printSubset(ans+ch,ros);
//     printSubset(ans,ros);

// }

void printSubset(string ans, string original, vector<string> &subsets){
    if(original.length() == 0){
        subsets.push_back(ans);
        return;
    }
    char ch = original[0];
    string ros = original.substr(1);
    printSubset(ans+ch,ros,subsets);
    printSubset(ans,ros,subsets);

}


int main (){
    string str = "abc";
    vector<string> subsets;
     //  printSubset("",str);
    printSubset("",str,subsets);
    for(string s: subsets) cout<<s<<" ";
}