#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* random;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->random = NULL;
    }
};

Node* copyRandomList(Node* head){
    // step 1 creat depp copy without random pointer
    Node* dummy = new Node(0);
    Node* tempC = dummy;
    Node* temp = head;
    while(temp){
        Node* a = new Node(temp->val);
        tempC->next = a;
        tempC = tempC->next;
        temp = temp->next;  

    }
    Node* duplicate = dummy->next;
    // step -> alternate connection
    Node* a = head;
    Node* b= duplicate;
    dummy = new Node(-1);
    Node* tempD = dummy;
    while(a){
       
        tempD->next = a;
        a = a->next;
        tempD = tempD->next;
        tempD->next = b;
        b = b->next;
        tempD = tempD->next;

    }
   dummy = dummy->next;   

   // step 3 -> assigning random pointer of duplicate
   Node* t1 = dummy;
   while(t1){
    Node* t2 = t1->next;
    if(t1->random) t2->random = t1->random->next;
    t1 = t1->next->next;

   }
   // step 4 -> removing the connection
   Node* d1 =  new Node(-1);
   Node* d2 =  new Node(-1);
   t1 = d1;
   Node* t2 = d2;
   Node* t = dummy;
   while(t){
    t1->next = t;
    t = t->next;
    t1 = t1->next;
    t2->next = t;
    t = t->next;
    t2 = t2->next;
   }
   t1->next = NULL;
   t2->next = NULL;
   d1 = d1->next; // original
   d2 = d2->next;

 return  d2;

}

int main() {
    // Create nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    // Next pointers
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // Random pointers
    n1->random = n3; // 1 -> 3
    n2->random = n1; // 2 -> 1
    n3->random = n4; // 3 -> 4
    n4->random = n2; // 4 -> 2

    Node* head = n1;

    // Copy list
    Node* copiedHead = copyRandomList(head);

    // Print copied list (val + random val)
    Node* temp = copiedHead;
    while (temp) {
        cout << "Val: " << temp->val;
        if (temp->random)
            cout << ", Random: " << temp->random->val;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }

    return 0;
}
