#include<iostream>
#include<vector>
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
   if(head==NULL || head->next == NULL) return head;
   Node* newHead = reverseList(head->next);
   head->next->next = head;
   head->next = NULL;
   return newHead;
}


Node* reverseBetween(Node* head ,int left,int right){
    Node* temp = head;
    Node* a = NULL;
    Node* b = NULL;
    Node* c = NULL;
    Node* d = NULL;
    int n = 1;
    while(temp != NULL){
        if(n == left-1){
            a = temp;
        }
        if(n == left){
            b = temp;
        }
        if(n == right){
            c = temp;
        }
        if(n == right+1){
            d = temp;
        }
        temp = temp->next;
        n++;
    }
    if(a != NULL){
        a->next = NULL;
    }
     if(c) c->next = NULL;
    // reverse the linked list from b to c
    c = reverseList(b);
    // connect the linked list
    if(a != NULL){
        a->next = c;
    }
    b->next = d;
    if(a) return head;
    return c;
}


Node* reverseEvenLengthGroups(Node* head){
    Node* temp = head;
    int gap = 1;
    while( temp && temp->next ){
        int remLen = 0;
        Node* t = temp->next;
        for(int i =1;i<=gap+1 && t != NULL;i++){
            t = t->next;
            remLen++;

        }
        if(remLen< gap+1) gap = remLen-1;
        if(gap%2!=0) reverseBetween(temp,2,2+gap);
        gap++;
        for(int i=1; temp != NULL && i<=gap;i++){
            temp = temp->next;
        }
    }

    return head;
}
 

void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);


    cout << "Original List: ";
    printList(head);

    head = reverseEvenLengthGroups(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}