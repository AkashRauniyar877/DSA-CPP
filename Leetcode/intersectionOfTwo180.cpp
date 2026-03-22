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
 Node* intersectionNode(Node* headA, Node* headB){
    int lenA = 0;
    int lenB = 0;
    Node* tempA = headA;
    Node* tempB = headB;
    while(tempA != NULL){
        lenA++;
        tempA = tempA->next;
    }
    while(tempB != NULL){
        lenB++;
        tempB = tempB->next;
    }
    int diff = abs(lenA - lenB);
    tempA = headA;
    tempB = headB;
    if(lenA > lenB){
        for(int i=0; i<diff; i++){
            tempA = tempA->next;
        }
        while(tempA != tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
    else{
        for(int i=0; i<diff; i++){
            tempB = tempB->next;
        }
        while(tempA != tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
   
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
    Node* f = new Node(60);
    Node* g = new Node(70);
    f->next = g;
    g->next = c; // intersection point
    display(a);
    display(f);
    Node* ans = intersectionNode(a, f);  
    if(ans)
        cout << "Intersection at: " << ans->val;
    else
        cout << "No intersection";
   


   
 
}