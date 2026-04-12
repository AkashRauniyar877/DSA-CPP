#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
 int val;
    Node* next;
        Node(int val){
            this->val =  val;
            this->next = NULL;
        }
};
      
class Queue{
public:
      int size;
      Node* head;
      Node* tail;
      Queue(){
        head = tail = NULL;
        size = 0;
      }
      void push(int val){
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

     void pop(){
            if(size == 0) {
                cout<<"Queue is empty"<<"\n";
                return;
            }
            Node* temp = head;
             head = head->next;
            size--;  
            delete(temp);
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
          cout<<endl;
      }
      int sizee(){
        return size;
      }

      bool empty(){
        if(size==0) return true;
        else return false;
      }


   
};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
    q.push(60);
    q.display();
    q.pop();
    q.display();
   

}