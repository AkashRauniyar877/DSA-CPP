#include<iostream>
#include<stack>
using namespace std;
void print(stack<int>st){
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
int main(){
    stack<int> st;
    cout<<st.size()<<endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    print(st);
    stack<int> a;
    stack<int> b;
    while(st.size()>0){
        a.push(st.top());
        st.pop();
    }
    while(a.size()>0){
        b.push(a.top());
        a.pop();
    }

    while(b.size()>0){
        st.push(b.top());
        b.pop();
    }
    cout<<endl;
    print(st);
   
    

}