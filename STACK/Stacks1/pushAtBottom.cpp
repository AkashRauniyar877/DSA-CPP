#include<iostream>
#include<stack>
using namespace std;
void print(stack<int> &st){
     stack<int> temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }
    while(temp.size()>0){
        cout<<temp.top()<<" ";
        st.push(temp.top());
         temp.pop();
    }

}
void pushAtBottom(stack<int> &st,int val){
    stack<int>temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }

}

int main(){
    stack<int> st;
    cout<<st.size()<<endl;
    st.push(10);
    st.push(12);
    st.push(15);
    st.push(16);
    st.push(60);
    print(st);
    pushAtBottom(st,80);
    cout<<endl;
    print(st);
   

}