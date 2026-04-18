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
 int findPredecessorInBST(Node* root, int key){
    Node* predecessor = NULL;
    while (root) {
        if (key > root->val) {
            predecessor = root; // Update predecessor
            root = root->right; // Move right
        } else {
            root = root->left; // Move left
        }
    }
    return predecessor ? predecessor->val : -1; // Return -1 if no predecessor found
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
    int predecessor = findPredecessorInBST(root, key);
    if (predecessor != -1) {
        cout << "Inorder Predecessor of " << key << " is: " << predecessor << endl;
    } else {
        cout << "No Inorder Predecessor found for " << key << endl;
    }

    return 0;
}