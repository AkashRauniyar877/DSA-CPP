#include<iostream>
#include<climits>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

};
void displayTree(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}
void trim(Node* root, int lo, int hi){
    if(root==NULL) return ;
    while(root->left !=NULL){
        if(root->left->val <lo){
            root->left = root->left->right;
        }
        else if(root->left->val > hi){
            root->left = root->left->left;
        }
        else break;
    }
     while(root->right !=NULL){
        if(root->right->val > hi){
            root->right = root->right->left;
        }
        else if(root->right->val < lo){
            root->right = root->right->right;
        }
        else break;
    }
    trim(root->left,lo,hi);
    trim(root->right,lo,hi);
}
Node* trimBST(Node* root, int lo,int hi){
    Node* dummy = new Node(INT_MAX);
    dummy->left = root;
    trim(dummy,lo,hi);
    return dummy->left;   
}
int main(){
    // Creating BST manually
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    cout << "Tree (Preorder): ";
    displayTree(root);
    cout << endl;

  
    int lo = 6, hi = 13;
    Node* trimmedRoot = trimBST(root, lo, hi);
    
    cout << "Trimmed Tree (Preorder): ";
    displayTree(trimmedRoot);
    cout << endl;

    return 0;
}