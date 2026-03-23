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


Node* reverseList(Node* head ,int left,int right){
    Node* temp = head;
    Node* a = NULL;
    Node* b = NULL;
    Node* c = NULL;
    Node* d = NULL;
    int n = 1;
    while(temp != NULL){
        if(n == left-1){
            a = temp;
        }
        if(n == left){
            b = temp;
        }
        if(n == right){
            c = temp;
        }
        if(n == right+1){
            d = temp;
        }
        temp = temp->next;
        n++;
    }
    if(a != NULL){
        a->next = NULL;
    }
    c->next = NULL;
    // reverse the linked list from b to c
    c = reverseList(b);
    // connect the linked list
    if(a != NULL){
        a->next = c;
    }
    b->next = d;
    if(a) return head;
    return c;
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
    Node* f = new Node(60);
    Node* g = new Node(70);
    Node* h = new Node(80);
    a->next = b;
    b->next = c;
    c->next = d;   
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;
    int left = 2;
    int right = 5;
    Node* head = reverseList(a,left,right);
    display(head);
}

