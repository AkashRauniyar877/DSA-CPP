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

  Node* searchBST(Node* root, int val){
        if(root==NULL) return NULL;
        else if(root->val==val)  return root;
        else if(root->val> val) return searchBST(root->left,val);
        else return searchBST(root->right,val);
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

  
    int key = 7;
    Node* result = searchBST(root, key);
    if(result != NULL)
        cout << "Value " << key << " found in BST";
    else
        cout << "Value " << key << " not found in BST";

    return 0;
}
