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
Node* merge(Node* a, Node* b){
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
// sc= o(1) tc = o(nlogn)
 Node* sortList(Node* head){
    if(head == NULL || head->next == NULL) return head;
    // find the middle of the list
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    // add slow to the middle of the list
    Node* a = head;
    Node* b = slow->next;
    slow->next = NULL; // break the list into two halves
    a = sortList(a);
    b = sortList(b);
    // merge the sorted halves
    Node* c = merge(a,b);
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
    Node* b = new Node(30);
    Node* c = new Node(20);
    Node* d = new Node(40);
    Node* e = new Node(50);
    a->next = b;
    b->next = c;
    c->next = d;   
    d->next = e;
    cout<<"Original List: ";
    display(a);
    Node* sortedHead = sortList(a);
    cout<<"Sorted List: ";
    display(sortedHead);
}