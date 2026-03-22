#include<iostream>
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
// in two pass

 /* Node* removeNthFromENd(Node* head , int n){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    // nth from end  = len - n + 1 from start
    int m = len - n+1;
    int idx = m-1; // the idx of the node to be removed from start
    temp = head;
    if(idx == 0){
        head = head->next;
        return head;
    }
    for(int i =1; i<=idx-1; i++){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
} */

// in one pass
Node* removeNthFromEnd(Node* head , int n){
    Node* slow = head;
    Node* fast = head;

    // traverse fast to n+1 node
    for(int i=0; i<n+1; i++){
        if(fast == NULL){
            // if n is equal to the length of the list, remove the head
            return head->next;
        }
        fast = fast->next;
    }
    // move both pointers until fast reaches the end
    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    // slow now points to the node before the one to be removed
    slow->next = slow->next->next;
    return head;
}
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    a->next = b;
    b->next = c;
    c->next = d;   
    d->next = e;
    display(removeNthFromEnd(a, 2));
}