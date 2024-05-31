/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

void PreOrder(TreeNode* root, vector<int> &v){
    if(root == NULL) return;
    // root left right
    v.push_back(root->val);
    PreOrder(root->left,v);
    PreOrder(root->right,v);
}

public:
    vector<int> preorderTraversal(TreeNode* root) {
        // // Recursion
        // vector<int> pre;
        // PreOrder(root, pre);
        // return pre;

        // Iterative
        vector<int> preorder;
        if(root == NULL) return preorder;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            preorder.push_back(root->val);
            if(root -> right != NULL){
                st.push(root->right);
            }
            if(root -> left != NULL){
                st.push(root->left);
            } 
        }
        return preorder;
    }
};