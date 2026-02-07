#include<iostream>
using namespace std;
int power(int a, int b){
  
    int p = 1;
    for(int i=1;i<=b;i++){
        p *= a;
    }
    return p;
}
int power1(int a,int b){
    if(b == 0) return 1;
    return a*power1(a,b-1);

}

int main(){

int a, b;
cout<<"Enter base : ";
cin>>a;
cout<<"Enter power : ";
cin>>b;
cout<<a<<" raised to the power "<<b<<" is "<<power1(a,b)<<" .";

}