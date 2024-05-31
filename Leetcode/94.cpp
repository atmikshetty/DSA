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
        vector<int> inorder;
        Inorder(root, inorder);
        return inorder;
    }
};