#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node* child;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
        this->child = NULL;
    }
};

Node* flatten(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* a= temp->next;
        if(temp->child !=NULL){
            Node* c= temp->child;
            temp->child = NULL; // V IMP
            c= flatten(c);  // recurssion
            temp->next = c;
            c->prev = temp;
            while(c->next != NULL){
                c = c->next;

            }
            c->next = a;
            if(a) a->prev = c;
        }
        temp = temp->next;
    }
    return head;
}