#include<iostream>
#include<string>
using namespace std;

 string largestEven(string &s) {
    int n = s.size();
    for(int i=n-1;i>=0;i--){
        if(s[i]=='2') return s;
        else {
            s[i] =='1';
            s.pop_back();
        }
    }
    return s;
 }


int main(){
 string s = "1211";
 cout<< largestEven(s);
}