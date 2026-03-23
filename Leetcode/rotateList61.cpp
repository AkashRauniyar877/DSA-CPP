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

Node* rotateList(Node* head , int k){
    if(k == 0 || head == NULL || head->next == NULL) return head;
    Node* temp = head;
    Node* tail = NULL;
    int n = 0;
    while(temp != NULL){
        n++;
        tail = temp;
        temp = temp->next;
    }
    k = k%n; // in case k is greater than n
    if(k == 0) return head; // no rotation needed
    // place temp at the (n-k)th node
    temp = head;
    for(int i=1; i<=n-k-1; i++){
        temp = temp->next;
    }
    // temp is now at the (n-k)th node
    tail->next = head; // connect the tail to the head
    head = temp->next; // new head is the (n-k+1)th
    temp->next = NULL; // break the link to form the new list
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
    int k = 2;
    cout<<"Original List: ";
    display(a);
    Node* rotatedHead = rotateList(a, k);
    cout<<"Rotated List: ";
    display(rotatedHead);
    return 0;
}