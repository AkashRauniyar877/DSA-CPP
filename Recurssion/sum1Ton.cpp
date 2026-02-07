#include<iostream>
using namespace std;
void sum1toN(int sum, int n){ //Parametrized
    if(n==0){
        cout<<sum<<endl;
        return;
    }
    sum1toN(sum+n,n-1);
}
// Return type
int sum1ToN(int n){
    if(n==0) return 0;
    return  n + sum1ToN(n-1);
}


int main(){
    sum1toN(0,6);
   cout<< sum1ToN(10);

}