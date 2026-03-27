#include<iostream>
#include<vector>
using namespace std;
class Stack{
public:
    vector<int>arr;
    
    void push(int val){
        arr.push_back(val);
    }
    void pop(){
        if(arr.size()==0){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        arr.pop_back();
    }
    int top(){
        if(arr.size()==0){
           cout<<"Stack is Empty"<<endl;
            return -1; 
        }
        return arr[arr.size()-1];
    }
    int size(){
        return arr.size();
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(30);
    st.push(40);
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.top()<<endl;

}