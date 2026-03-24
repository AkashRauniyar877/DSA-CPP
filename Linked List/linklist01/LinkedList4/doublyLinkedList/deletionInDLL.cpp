#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DLL{
public:    
    Node* head;
    Node* tail;
    int size;
    DLL(){
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }
    void deleteAtHead(){
        if(head == NULL){
            cout<<"List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head != NULL){
            head->prev = NULL;
        }
        else{
            tail = NULL;
        }
        delete temp;
        size--;
    }
};