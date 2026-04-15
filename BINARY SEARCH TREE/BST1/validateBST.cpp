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
long long maxTree(Node* root){
    if(root==NULL) return LLONG_MIN;
    return max((long long)root->val,max(maxTree(root->left),maxTree(root->right)));
}
long long  minTree(Node* root){
     if(root==NULL) return LLONG_MAX;
    return min((long long)root->val,min(minTree(root->left),minTree(root->right)));

}
bool isValidBST(Node* root){
    if(root==NULL) return true;
     else if((long long)root->val <= maxTree(root->left)) return false;
    else if((long long)root->val >= minTree(root->right)) return false;
    return isValidBST(root->left) && isValidBST(root->right);

}
int main(){
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

   if(isValidBST(root)) cout<<"The tree is a valid BST";
   else cout<<"The tree is not a valid BST";

}