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

class LinkedList{ 
public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
        void insertAtHead(int val){
            Node* temp = new Node(val);
            if(size == 0){
                head = temp;
                tail = temp;
            }
            else{
            temp->next = head;
            head =  temp;
    
            }
            size++;
        }
        void deleteAtHead(){
            if(size == 0) {
                cout<<"Linked List is empty"<<"\n";
                return;
            }
             head = head->next;
            size--;  
        }
        void deleteAtTail(){
            if(size==0){
                cout<<"Linked List is empty"<<"\n";
                return;
            }
            if(size == 1){
                head = NULL;
                tail = NULL;
            }
            else{
                Node* temp = head;
                while(temp->next != tail){
                    temp = temp->next;
                }
                temp->next = NULL;
                tail = temp;
                size--;
            }
        }
        void deleteAtIdx(int idx){
            if(idx<0 || idx >= size) {
                cout<<"Invalid Index"<<"\n";
                return;
            }
            else if(idx == 0) deleteAtHead();
            else if(idx == size-1) deleteAtTail();
            else{
                Node* temp = head;
                for(int i=0;i<idx-1;i++){
                    temp = temp->next;
                }
                temp->next = temp->next->next;
                size--;
            }
        }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    LinkedList ll;
    ll.insertAtHead(10);
    ll.insertAtHead(20);
    ll.insertAtHead(30);
    ll.insertAtHead(40);
    ll.insertAtHead(50);
    ll.insertAtHead(60);
    ll.display();
    ll.display();
    cout<<"Size of linked list is: "<<ll.size<<endl;
    ll.deleteAtHead();
    ll.display();
    ll.deleteAtTail();
    ll.display();
    ll.deleteAtIdx(2);
    ll.display();
  
}