#include<iostream>
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
void displayTree(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}
Node* helper(vector<int> &arr,int lo, int hi){
    if(lo>hi) return NULL;
    int mid = lo+ (hi-lo)/2;
    Node* root = new Node (arr[mid]);
    root->left = helper(arr,lo,mid-1);
    root->right = helper(arr,mid+1,hi);
    return root;
}

Node* sortedArrayToBST(vector<int> & arr) {
    int n= arr.size();
    return helper(arr,0,n-1);
        
    }


int main(){
    vector<int> nums = {-10, -3, 0, 5, 9};
    Node* root = sortedArrayToBST(nums);
    cout << "Balanced BST (Preorder): ";
    displayTree(root);
    cout << endl;
    return 0;
}