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
    void deleteAtTail(){
        if(tail == NULL){
            cout<<"List is empty\n";
            return;
        }
        else if(size == 1){
            deleteAtHead();
            return;
        }
        Node* temp = tail->prev;
        temp->next = NULL;
        tail = temp;
        size--;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }

    void deleteAtIdx(int idx){
        if(idx < 0 || idx >= size){
            cout<<"Invalid index\n";
            return;
        }
        if(idx == 0){
            deleteAtHead();
            return;
        }
        if(idx == size-1){
            deleteAtTail();
            return;
        }
        Node* temp = head;
        for(int i=0;i<idx;i++){
            temp = temp->next;
        }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        delete temp;
        size--;
    }

    int getAtIdx(int idx){
        if(idx < 0 || idx >= size){
            cout<<"Invalid index\n";
            return -1;
        }
        else if(idx ==0){
            return head->val;
        }
        else if(idx == size-1){
            return tail->val;
        }
        Node* temp = head;
        for(int i=0;i<idx;i++){
            temp = temp->next;
        }
        return temp->val;
    }

    // getAtIdx optimize version
    int getAtIdxOpt(int idx){
        if(idx < 0 || idx >= size){
            cout<<"Invalid index\n";
            return -1;
        }
        else if(idx ==0){
            return head->val;
        }
        else if(idx == size-1){
            return tail->val;
        }
        Node* temp;
        if(idx < size/2){
            temp = head;
            for(int i=0;i<idx;i++){
                temp = temp->next;
            }
        }
        else{
            temp = tail;
            for(int i=size-1;i>idx;i--){
                temp = temp->prev;
            }
        }
        return temp->val;
    }
};

int main(){
    DLL dl;
    dl.insertATail(10);
    dl.insertATail(20);
    dl.insertATail(30);
    dl.insertAtHead(5);
    dl.insertATail(40);
    dl.insertAtIdx(2,15);
    dl.display();
    dl.deleteAtHead();
    dl.display();
    dl.deleteAtTail();
    dl.display();
    dl.deleteAtIdx(2);
    dl.display();
    cout<<dl.getAtIdx(1)<<"\n";
    return 0;
}
