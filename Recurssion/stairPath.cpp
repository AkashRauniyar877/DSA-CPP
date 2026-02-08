#include<iostream>

using namespace std;
int stairPath(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    return stairPath(n-1) + stairPath(n-2);

}

 int main(){
   cout<<stairPath(5);

}