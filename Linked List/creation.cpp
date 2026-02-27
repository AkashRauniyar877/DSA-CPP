#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;   // Step 1: NULL pointer

    // Create first node
    head = new Node();
    head->data = 10;
    head->next = NULL;

    // Create second node
    Node* second = new Node();
    second->data = 20;
    second->next = NULL;

    head->next = second;

    // Print Linked List
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}