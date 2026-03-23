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
 // Iterative approach
Node* reverseList(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* Next = NULL;
    while(curr != NULL){
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
}

// Recursive approach
Node* reverseList(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
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
    Node* head = reverseList(a);
    display(head);
}