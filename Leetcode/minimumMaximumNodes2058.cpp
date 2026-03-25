#include<iostream>
#include<vector>
#include<climits>
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

vector<int> nodesBetweenCriticalPoints(Node* head) {
    int idx = 1;
    int fidx = -1;
    int sidx = -1;
    Node* a = head;
    Node* b = head->next;
    Node* c = head->next->next;
     if(c==NULL){
        return {-1,-1};
    }
    while(c != NULL){
        if((b->val > a->val && b->val > c->val) || (b->val < a->val && b->val < c->val)){
            if(fidx == -1){
                fidx = idx;
            }
            else{
                sidx = idx;
            }
        }
        a = a->next;
        b = b->next;
        c = c->next;
        idx++;
    }
    if(sidx == -1){
        return {-1,-1};
    }
    int maxd = sidx - fidx;
    fidx = -1;
    sidx = -1;
    int mind = INT_MAX;
    a = head;
    b = head->next;
    c = head->next->next;
    idx = 1;
    while(c != NULL){
        if((b->val > a->val && b->val > c->val) || (b->val < a->val && b->val < c->val)){
         fidx = sidx;
         sidx = idx;
         if(fidx != -1){
         mind = min(mind,sidx - fidx);
        }
    }
        a = a->next;
        b = b->next;
        c = c->next;
        idx++;
    }

    return {mind,maxd};
}


int main(){
    Node* head = new Node(5);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(1);
    vector<int> ans = nodesBetweenCriticalPoints(head);
    cout<<ans[0]<<" "<<ans[1]<<"\n";
    return 0;
}