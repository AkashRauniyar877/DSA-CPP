#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int>m;
    pair<string,int>p1;
    p1.first = "Akash";
    p1.second = 11;
    m.insert(p1);
    // pair<string,int>p2;
    // p2.first = "vikash";
    // p2.second = 12;
    // m.insert(p2);
    // pair<string,int>p3;
    // p3.first = "Aman";
    // p3.second = 16;
    // m.insert(p3);

    m["Vikash"] = 12;


    for(pair<string,int> p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }

}