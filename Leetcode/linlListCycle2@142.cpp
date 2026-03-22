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
  Node* detectCycle(Node* head) {
            if(head == NULL){
                return NULL;
            }
            Node* slow = head;
            Node* fast = head;
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast){
                    // cycle detected, find the entry point
                    Node* temp = head;
                    while(temp != slow){
                        temp = temp->next;
                        slow = slow->next;
                    }
                    return temp; // entry point of the cycle
                }
            }
            return NULL; // no cycle
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
    // create a cycle
    e->next = c;
    Node* cycleEntry = detectCycle(a);
    if(cycleEntry){
        cout << "Cycle detected at node with value: " << cycleEntry->val << "\n";
    } else {
        cout << "No cycle detected.\n";
    }
}