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

Node* merge(Node* a, Node* b){
    Node* c = new Node(-1); // dummy node
    Node* tempC = c;
    while(a != NULL && b != NULL){
        if(a->val <= b->val){
            tempC->next = a;
            tempC = a;
            a = a->next;
        }
        else{
            tempC->next = b;
            tempC = b;
            b = b->next;
        }
    }
    if(a == NULL){
        tempC->next = b;
    }
    else{
        tempC->next = a;
    }
    return c->next;
}
// tc =(n*k^2) sc = o(1)
Node* mergeKLists(vector<Node*>& arr){
    if(arr.size() == 0) return NULL;
    if(arr.size() == 1) return arr[0];
    while(arr.size()>1){
        Node* a = arr[arr.size()-1];
        arr.pop_back();
        Node* b = arr[arr.size()-1];
        arr.pop_back();
        Node* c = merge(a,b);
        arr.push_back(c);
    }
    return arr[0];

}

// tc = o(n*k*logk) sc = o(1)
Node* mergeKLists(vector<Node*>& arr){
    if(arr.size() == 0) return NULL;
    if(arr.size() == 1) return arr[0];
    while(arr.size()>1){
        Node* a = arr[0];
        arr.erase(arr.begin());
        Node* b = arr[0];
        arr.erase(arr.begin());
        Node* c = merge(a,b);
        arr.push_back(c);
    }
    return arr[0];

}
int main() {
    // list1: 1 -> 4 -> 7
    Node* a1 = new Node(1);
    a1->next = new Node(4);
    a1->next->next = new Node(7);

    // list2: 2 -> 5 -> 8
    Node* a2 = new Node(2);
    a2->next = new Node(5);
    a2->next->next = new Node(8);

    // list3: 3 -> 6 -> 9
    Node* a3 = new Node(3);
    a3->next = new Node(6);
    a3->next->next = new Node(9);

    vector<Node*> arr;
    arr.push_back(a1);
    arr.push_back(a2);
    arr.push_back(a3);

    Node* ans = mergeKLists(arr);

    // print merged list
    Node* temp = ans;
    while(temp){
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL";

    return 0;
}