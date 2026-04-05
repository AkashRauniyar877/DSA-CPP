#include<iostream>
#include<queue>
#include<stack>
using namespace std;
//pop efficient
class MyQueue {
public:
    stack<int>st;
    stack<int>h;

    MyQueue() {
        
    }
    
    void push(int x) {
        if(st.size()==0){
        st.push(x);
        return;
        }
        else{
             while(st.size()>0){
            h.push(st.top());
            st.pop();
        }
         st.push(x);
           while(h.size()>0){
            st.push(h.top());
            h.pop();
        }

        }
        
    }
    
    int pop() {
      int x = st.top();
      st.pop();
      return x;
    }
    
    int peek() {
         return st.top();
    }
    
    bool empty() {
        if(st.size()==0) return true;
        else return false;
        
    }
};

int main(){
      MyQueue q;

    // push elements
    q.push(10);
    q.push(20);
    q.push(30);

    // peek front
    cout << "Front: " << q.peek() << endl;   // 10

    // pop elements
    cout << "Popped: " << q.pop() << endl;   // 10
    cout << "Popped: " << q.pop() << endl;   // 20

    // check empty
    if (q.empty())
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";

    // more operations
    q.push(40);
    cout << "Front: " << q.peek() << endl;   // 30

    
}