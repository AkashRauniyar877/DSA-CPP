#include<iostream>
using namespace std;
#include<vector>
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

vector<vector<int>> spiralMAtrix(int m, int n, Node* head){
     vector<vector<int>> arr(m, vector<int>(n, -1)); // initialize with -1
     int minr = 0;
     int maxr = m-1;
     int minc = 0;
     int maxc = n-1;
     int count = 0;
     Node* temp = head;
     while(minr<= maxr && minc <= maxc){
        // right
        for(int j = minc;j<=maxc;j++){
            if(temp == NULL) break;
            arr[minr][j] = temp->val;
            temp = temp->next;
        }
        minr++;
        if(minr>maxr || minc > maxc) break;
        // down
        for(int i = minr; i<=maxr; i++){
            if(temp == NULL) break;
             arr[i][maxc] = temp->val;  
            temp = temp->next;
        }
        maxc--;
        if(minr>maxr || minc > maxc) break;
        // left
        for(int j = maxc; j>=minc; j--){
            if(temp == NULL) break;
             arr[maxr][j] = temp->val;  
            temp = temp->next;
        }
        maxr--;
        if(minr>maxr || minc > maxc) break;
        // up
        for(int i = maxr; i>=minr; i--){
            if(temp == NULL) break;
             arr[i][minc] = temp->val;  
            temp = temp->next;
        }
        minc++;
        if(minr>maxr || minc > maxc) break;

     }
        return arr;
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    int m = 3;
    int n = 3;
    vector<vector<int>> result = spiralMAtrix(m, n, a);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
    

}