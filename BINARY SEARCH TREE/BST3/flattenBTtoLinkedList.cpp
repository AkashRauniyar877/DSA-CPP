#include<iostream>
#include<climits>
#include<vector>
#include<stack>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

};

 vector<TreeNode*> preorder(TreeNode* root){
        vector<TreeNode* >ans;
        stack<TreeNode*>st;
        if(root!=NULL) st.push(root);
        while(st.size()>0){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp);
            if(temp->right!=NULL) st.push(temp->right);
            if(temp->left!=NULL) st.push(temp->left);
        }
        return ans;
    }
    void flatten(TreeNode* root){
        vector<TreeNode*> ans = preorder(root);
        int n = ans.size();
        for(int i=0;i<n-1;i++){
            ans[i]->right = ans[i+1];
            ans[i]->left = NULL;
          
        }
    } 

    int main() {
    // Creating tree:
    //       1
    //      / \
    //     2   5
    //    / \   \
    //   3   4   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    // Flatten the tree
    flatten(root);

    // Print flattened tree (right-skewed list)
    TreeNode* curr = root;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->right;
    }

}
   