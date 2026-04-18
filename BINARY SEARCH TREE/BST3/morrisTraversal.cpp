#include<iostream>
#include<climits>
#include<vector>
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

vector<int> inorderTraversal(Node* root){
    Node* curr = root;
    vector<int>ans;
    while(curr != NULL){
        if(curr->left != NULL){
            Node* pred = curr->left;
            while(pred->right != NULL && pred->right != curr){
                pred = pred->right;
            }
            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }

        }
        else{
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
    return ans;
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

    vector<int>inorder = inorderTraversal(root);
    for(int val: inorder){
        cout<<val<<" ";
    }
}