#include<iostream>
using namespace std;
class Node{
public:    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
Node* middleNode(Node* head) {
      int len = 0;
      Node* temp = head;
      while(temp != NULL){
          len++;
          temp = temp->next;
      }
      int mid = len/2;
      Node* temp1 = head;
      for(int i=0; i<mid; i++){
          temp1 = temp1->next;
      }
      return temp1;

    }

    // in one pass
Node* middleNode(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* middleLeftNode(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while( fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
  cout<< middleNode(a)->val<<"\n";
}