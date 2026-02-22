#include<iostream>
#include<vector>
using namespace std;

 int factorial(int n){
        if(n==0 || n==1) return 1;
        return n * factorial(n - 1);
        
    }

    bool isDigitorialPermutation(int n) {
        int a = n;
        int digit = 0;
        int sum = 0;
        while(n>0){
            digit = n%10;
            sum += factorial(digit);
            n /= 10;
        }
      if(sum==a) return true;
        return false;
    }
    int main(){
        int n = 145;
        cout<<isDigitorialPermutation(n);
        cout<<"\n";
        int m = 415;
        cout<<isDigitorialPermutation(m);
    }