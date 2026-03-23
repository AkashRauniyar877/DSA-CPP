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
// palindrome-> partition/merge sort-> new node
void reorderList(Node* head){
     Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is at the middle of the linked list
    Node* b = reverseList(slow->next);
    Node* a = head;
    slow->next = NULL;
    // merge the two linked list alternatively
    Node* c = new Node(10);
    Node* tempC = c;
    Node* tempA = a;
    Node* tempB = b;
    while(tempA != NULL && tempB != NULL){
        tempC->next = tempA;
        tempA = tempA->next;
        tempC = tempC->next;

        tempC->next = tempB;
        tempB = tempB->next;
        tempC = tempC->next;
    }
    tempC->next = tempA;
    head = c->next;

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
    reorderList(a);
    display(a);
}