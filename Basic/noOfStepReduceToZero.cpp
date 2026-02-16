#include<iostream>
#include<vector>
using namespace std;
    int numberOfSteps(int num) {
        int count =0;
        while(num>0){
            if(num%2==0){
              num = num /2;
                count++;
            }
            else{
               num= num-1;
                count++;
            }
        }
        return count;
        
    }
 

int main(){
   int n =8;
   cout<<numberOfSteps(n);
   
}