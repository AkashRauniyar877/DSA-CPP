#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}
void displayReverse(Node* tail){
    while(tail != NULL){
        cout<<tail->val<<" ";
        tail = tail->prev;
    }
    cout<<"\n";
}

void displayRec(Node* head){
    if(head == NULL){
        return;
    }
    cout<<head->val<<" ";
    displayRec(head->next);
}
void displayRecReverse(Node* head){
    if(head == NULL){
        return;
    }
    displayRecReverse(head->next);
    cout<<head->val<<" ";
}
   


int main(){
    // 10 20 30 40 50
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    c->next = d;
    d->prev = c;
    d->next = e;
    e->prev = d;
    // display the linked list in forward direction
    display(a);
    // display the linked list in backward direction
    displayReverse(e);
}