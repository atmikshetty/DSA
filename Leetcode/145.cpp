/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

    void Postorder(TreeNode* root, vector<int>& v) {
        if (root == NULL)
            return;
        // left right root
        Postorder(root->left, v);
        Postorder(root->right, v);
        v.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        // // Recursive
        // vector<int> post;
        // Postorder(root, post);
        // return post;

        // Iterative
        vector<int> postorder;
        if(root == NULL) return postorder;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root -> right != NULL){
                st1.push(root -> right);
            }
            if(root -> left != NULL){
                st1.push(root -> left);
            }
        }
        while(!st2.empty()){
            postorder.push_back(st2.top() -> val);
            st2.pop();
        }
        return postorder;
    }
};