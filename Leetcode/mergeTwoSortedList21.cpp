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

Node* mergeTwoLists(Node* a, Node* b){
    // sc= o(m+n)
    Node* tempA = a;
    Node* tempB = b;
    Node* c = new Node(-1); // dummy node
    Node* tempC = c;
    while(tempA != NULL && tempB != NULL){
        if(tempA->val <= tempB->val){
            Node* t = new Node(tempA->val);
            tempC->next = t;
            tempC = t;
            tempA = tempA->next;
        }
        else{
            Node* t = new Node(tempB->val);
            tempC->next = t;
            tempC = t;
            tempB = tempB->next;
        }
    }
    if(tempA ==NULL){
        tempC->next = tempB;
    }
    else{
        tempC->next = tempA;
    }

    return c->next;
}

// sc = o(1)
Node* mergeTwoLists(Node* a, Node* b){
    Node* c = new Node(-1); // dummy node
    Node* tempC = c;
    while(a != NULL && b != NULL){
        if(a->val <= b->val){
            tempC->next = a;
            tempC = a;
            a = a->next;
        }
        else{
            tempC->next = b;
            tempC = b;
            b = b->next;
        }
    }
    if(a == NULL){
        tempC->next = b;
    }
    else{
        tempC->next = a;
    }
    return c->next;
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    a->next = b;
    b->next = c;
    Node* d = new Node(15);
    Node* e = new Node(25);
    Node* f = new Node(35);
    d->next = e;
    e->next = f;
    Node* mergedHead = mergeTwoLists(a, d);
    Node* temp = mergedHead;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}