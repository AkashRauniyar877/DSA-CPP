#include<iostream>
#include<stack>
#include<climits>
#include<vector>
#include <algorithm>
using namespace std;

// not best approach
class MinStack {
public:
stack<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int>helper;
        int mn = INT8_MAX;
        while(st.size()>0){
            mn = min(mn,st.top());
            helper.push(mn);
            st.pop();
        }
         while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
        return mn;      
    }
}; 

// best approach tc->o(1) sc->o(n)
class MinStack {
public:
stack<int>st;
stack<int>helper;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(helper.size()==0 || val<helper.top()) helper.push(val);
        else helper.push(helper.top());
    }
    
    void pop() {
        st.pop();
        helper.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
           return helper.top();
    }
};

//  tc->o(n) sc->o(1) using vector
class MinStack {
public:
vector<int>v;
    MinStack() {
        
    }
    
    void push(int val) {
      v.push_back(val);
    }
    
    void pop() {
       v.pop_back();
    }
    
    int top() {
      return v[v.size()-1];
    }
    
    int getMin() {
        int mn = v[0];
        for(int i=1;i<v.size();i++){
            mn = min(mn,v[i]);
        }
         return mn;
    }
};

//  tc->o(1) sc->o(1)
class MinStack {
public:
stack<long long>st;
long long min; 
    MinStack() {
        min = LLONG_MAX;
    }
    
    void push(int val) {
        long long x =(long long) val;
     if(st.size()==0){
        st.push(x);
        min = x;
     }
     else if(x>=min) st.push(x);
     else {
        st.push(2*x-min);
        min = x;
     }

    }
    
    void pop() {
      if(st.top()<min) {
         // before popping make sure to change old minimum
         long long oldMin = 2*min -st.top();
        min = oldMin;
      }
        st.pop();
    }
    
    int top() {
      if(st.top()<min){
        return (int) min;
      }
      else return  (int)st.top();
    }
    
    int getMin() {
      return (int) min;
    }
};  