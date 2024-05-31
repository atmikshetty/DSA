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

void Inorder(TreeNode* root, vector<int> &v){
    if(root == NULL) return;
    // left root right
    Inorder(root->left, v);
    v.push_back(root->val);
    Inorder(root->right, v);
}

public:
    vector<int> inorderTraversal(TreeNode* root) {
        // // Recursion
        // vector<int> inorder;
        // Inorder(root, inorder);
        // return inorder;

        // Iterative
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> inorder;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node -> left;
            }
            else{
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node -> right;
            }
        }
        return inorder;
    }
};