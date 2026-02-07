#include<iostream>
using namespace std;
// using extra parameter
void print(int i, int n){
    if(i>n) return;
    cout<<i<<endl;
    print(i+1,n);
}

void print1(int n){
    if(n==0) return;
   
    print1(n-1);
     cout<<n<<endl;
}


int main(){

  int n;
  cout<<"Enter the number:";
  cin>> n;
  cout<<"\n";
  print(1,n);
    
}