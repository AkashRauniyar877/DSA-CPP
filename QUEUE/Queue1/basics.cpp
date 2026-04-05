#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void display(queue<int>& q){
    int n = q.size();
    for(int i=1;i<=n;i++){
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}

void reverse(queue<int>&q){
    stack<int> st;
    int n = q.size();
    for(int i = 1;i<=n;i++){
        int x = q.front();
        st.push(x);
        q.pop();
    }
    while(st.size()>0){
        int y = st.top();
        q.push(y);
        st.pop();
    }

}

int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
   display(q);
   // q.pop();
   reverse(q);
    display(q);

}