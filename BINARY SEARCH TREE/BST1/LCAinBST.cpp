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
Node* lowestCommonAncestor(Node* root, Node* p , Node* q){
    if(root->val==p->val || root->val==q->val) return root;
    else if(root->val > p->val && root->val < q->val) return root;
    else if(root->val < p->val && root->val > q->val) return root;
    else if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);
    else return lowestCommonAncestor(root->left,p,q);
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

  
    Node* p = root->left; // 5
    Node* q = root->right; // 15
    Node* lca = lowestCommonAncestor(root, p, q);
    if(lca != NULL)
        cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val;
    else
        cout << "LCA does not exist.";

    return 0;
}