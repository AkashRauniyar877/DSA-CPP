#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

     Node* reverseList(Node* head) {
        Node* t = head;
        stack<int>st;
        while(t!=NULL){
            st.push(t->val);
            t = t->next;
        }
        Node* a = NULL;
        Node* tail = NULL;
        while(!st.empty()){
            int val = st.top();
            st.pop();
           Node* temp = new Node(val);
            if(a== NULL){
               a = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
        }
        return a;
    }

    int main() {
        Node* head = new Node(1);
        head->next = new Node(2);
        head->next->next = new Node(3);
        head->next->next->next = new Node(4);
        head->next->next->next->next = new Node(5);
        Node* newHead = reverseList(head);
        Node* temp = newHead;
        while(temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        
        return 0;
    }