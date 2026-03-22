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

Node* deleteDuplicate(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* A = head;
    Node* B = head->next;
    while(B != NULL ){
        while (B != NULL && B->val == A->val){
            B = B->next;
        }
        A->next = B;
        A = B;
        if(B != NULL){
            B = B->next;
        }

    }
    return head;
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(10);
    Node* c = new Node(20);
    Node* d = new Node(30);
    Node* e = new Node(30);
    a->next = b;
    b->next = c;
    c->next = d;   
    d->next = e;
    deleteDuplicate(a);
    Node* temp = a;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}