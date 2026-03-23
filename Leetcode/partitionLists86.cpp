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

Node* partitionList(Node* head, int x){
    Node* low = new Node(100);
    Node* high = new Node(100);
    Node* tempLow = low;
    Node* tempHigh = high;
    Node* temp = head;
    while(temp != NULL){
        if(temp->val < x){
            tempLow->next = temp;
            temp = temp->next;
            tempLow = tempLow->next;
        }
        else{
            tempHigh->next = temp;
            temp = temp->next;
            tempHigh = tempHigh->next;
        }
    }
    tempLow->next = high->next;
    tempHigh->next = NULL;
    return low->next;
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
    Node* b = new Node(80);
    Node* c = new Node(30);
    Node* d = new Node(60);
    Node* e = new Node(50);
    Node* f = new Node(20);
    a->next = b;
    b->next = c;
    c->next = d;   
    d->next = e;
    e->next = f;
    int x = 35;
    Node* head = partitionList(a,x);
    display(head);
}