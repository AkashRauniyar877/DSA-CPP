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

bool isPalindrome(Node* head){
    // deep copy of the linked list
    Node* temp = head;
    Node* c = new Node (10);
    Node* tempC = c;
    while(temp != NULL){
        Node* newNode = new Node(temp->val);
        tempC->next = newNode;
        tempC = tempC->next;
        temp = temp->next;

    }
    c = c->next;
    // reverse the linked list
    c = reverseList(c);
    // compare the two linked list
    Node* a = head;
    Node* b = c;
    while(a != NULL && b != NULL){
        if(a->val != b->val){
            return false;
        }
        a = a->next;
        b = b->next;
    }
    return true;
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}
 // tc:o(n) sc:o(1) approach
bool isPalindrome(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is at the middle of the linked list
    Node* newHead = reverseList(slow->next);
    Node* a = head;
    Node* b = newHead;
    while(b != NULL){
        if(a->val != b->val){
            return false;
        }
        a = a->next;
        b = b->next;
    }
    return true;
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(20);
    Node* e = new Node(10);
    a->next = b;
    b->next = c;
    c->next = d;   
    d->next = e;
    cout<<isPalindrome(a)<<"\n";
    display(a);
}