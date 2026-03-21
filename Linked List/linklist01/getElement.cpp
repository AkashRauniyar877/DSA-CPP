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

class LinkedList{ //user defined data structure
public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getAtIdx(int idx){
        if(idx<0 || idx >= size) {
            cout<<"Invalid Index"<<"\n";
            return -1;
        }
        Node* temp = head;
        for(int i=0;i<idx;i++){
            temp = temp->next;
        }
        return temp->val;
    }
    void insertAtTail(int val){
        Node* temp = new Node(val);
        if(size == 0){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
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

     void insertAtIdx(int idx,int val){
        if(idx<0 || idx >size)  cout<<"Invalid Index"<<"\n";   
        else if(idx==0)  insertAtHead(val); 
        else if(idx==size)  insertAtTail(val);
        else{
            Node* t = new Node(val);
            Node* temp = head;
            for(int i=0;i<idx-1;i++){
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;

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
    ll.insertAtTail(10);
    ll.insertAtTail(20);
    ll.insertAtTail(30);

    cout<<"Size of linked list is: "<<ll.size<<endl;
    cout<<"Element at index 0 is: "<<ll.getAtIdx(0)<<endl;
    cout<<"Element at index 1 is: "<<ll.getAtIdx(1)<<endl;
    cout<<"Element at index 2 is: "<<ll.getAtIdx(2)<<endl;
    cout<<"Element at index 3 is: "<<ll.getAtIdx(3)<<endl;
    cout<<ll.getAtIdx(2)<<endl;

}