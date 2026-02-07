#include<iostream>
using namespace std;
    // int fact(int n){
    //     for(int j=1;j<=n;j++){
    //         int f = 1;
    //         for(int i=2;i<=j;i++) {
    //             f *= i;
    //         }
    //         cout<<f<<endl;
    //     }
    // }

    // Using Recursion
        int Fact(int n){
            int f = 1;
            if(n==0 || n==1) return 1;
            else return n*Fact(n-1);
        }

int main(){

  cout<<  Fact(5);
    
}