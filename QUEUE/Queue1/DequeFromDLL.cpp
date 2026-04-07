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

class Deque{
public:    
    Node* head;
    Node* tail;
    int size;
    Deque(){
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void pushBack(int val){
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

    void pushFront(int val){
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

      void popFront(){
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
    void popBack(){
        if(tail == NULL){
            cout<<"Queue is empty\n";
            return;
        }
        else if(size == 1){
            popFront();
            return;
        }
        Node* temp = tail->prev;
        temp->next = NULL;
        tail = temp;
        size--;
    }
   
     int front(){
          if(size==0){
             cout<<"Queue is empty"<<"\n";
                return -1;
          }
          return head->val;
        }

         int back(){
          if(size==0){
             cout<<"Queue is empty"<<"\n";
                return -1;
          }
          return tail->val;
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
    Deque dq;
    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushBack(30);
    dq.pushBack(40);
    dq.pushBack(50);
    dq.pushBack(60);
    dq.display();
    dq.popBack();
    dq.popFront();
    dq.display();
    dq.pushFront(89);
    dq.display();
}