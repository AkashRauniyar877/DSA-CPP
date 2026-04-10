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

    void insertATail(int val){
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;

    }

    void insertAtHead(int val){
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void insertAtIdx(int idx,int val){
        if(idx < 0 || idx > size){
            cout<<"Invalid index\n";
            return;
        }
        if(idx == 0){
            insertAtHead(val);
            return;
        }
        if(idx == size){
            insertATail(val);
            return;
        }
        Node* temp = new Node(val);
        Node* curr = head;
        for(int i=0;i<idx-1;i++){
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;
        temp->prev = curr;
        size++;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }

};

int main(){
    DLL dll;
    dll.insertATail(10);
    dll.insertATail(20);
    dll.insertATail(30);
    dll.display();
    dll.insertAtHead(5);
    dll.display();
    dll.insertAtIdx(2,15);
    dll.display();
}