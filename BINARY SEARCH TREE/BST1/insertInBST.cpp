#include<iostream>
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
Node* insertIntoBST(Node* root, int val){
    if(root==NULL) return new Node(val);
    else if(root->val >val){
        if(root->left==NULL){
            Node* temp = new Node(val);
            root->left = temp;     
        }
        else  insertIntoBST(root->left,val);
    }
    else{
         if(root->right==NULL){
            Node* temp = new Node(val);
            root->right = temp;
        }
        else insertIntoBST(root->right,val);
    }
    return root;

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

  
    int key = 6;
    insertIntoBST(root,key);
     cout << "Tree after insertion (Preorder): ";
    displayTree(root);
    cout << endl;

    return 0;
}