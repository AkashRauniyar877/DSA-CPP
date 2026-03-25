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

vector<Node*> splitListToParts(Node* head, int k) {
    int n = 0;
    Node* temp = head;
    // calculate length of linked list
    while(temp != NULL){
        n++;
        temp = temp->next;
    }
    // breaking list in k lists
    temp = head;
    vector<Node*> ans;
    int size = n/k;
    int rem = n%k;
    while(temp != NULL){
        Node* c = new Node(10);
        Node* tempC = c;
        int s = size;
        if(rem > 0){
            s++;
            rem--;
        }
        for(int i=1;i<=s;i++){
            tempC->next = temp;
            temp = temp->next;
            tempC = tempC->next;
        }
        tempC->next = NULL; // Very important step to break the list
        ans.push_back(c->next);
    }
    if(ans.size() < k){ // k>n
        int rem = k - ans.size();
        for(int i=0;i<rem;i++){
            ans.push_back(NULL);
        }
    }
    return ans;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next->next = new Node(10);

    vector<Node*> ans = splitListToParts(head, 3);
    for(int i=0;i<ans.size();i++){
        Node* temp = ans[i];
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
}