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
Node* iop(Node* root){
    Node* pred = root->left;
    while(pred->right !=NULL){
        pred = pred->right;
    }
    return pred;
}
Node* ios(Node* root){
    Node* suc = root->right;
    while(suc->left != NULL){
        suc = suc->left;
    }
    return suc;
}

 Node* deleteNode(Node* root, int key){
    if(root==NULL) return root;
        if(root->val ==key){
            // Case: 1 -> No Child
            if(root->left == NULL && root->right == NULL) return NULL;

            // Case 2: 1 Child
            if(root->left == NULL || root->right == NULL){
                if(root->left==NULL) return root->left;
                else return root->right;
            }

            // Case 3: 2 Child
             if(root->left != NULL && root->right != NULL) {
                //replace inorder predecessor
                Node* pred = iop(root);
                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val);
             }
        }
        else if(root->val >key){
            root->left = deleteNode(root->left, key);
        }
        else{
            root->right = deleteNode(root->right, key);
        }
        return root;

    }
int main() {
    // Create BST manually
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout << "Original Tree (Preorder): ";
    displayTree(root);
    cout << endl;

    int key = 30; // node to delete
    root = deleteNode(root, key);

    cout << "After Deletion (Preorder): ";
    displayTree(root);
    cout << endl;

    return 0;
}
