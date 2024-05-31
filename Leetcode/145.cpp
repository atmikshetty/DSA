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

void Postorder(TreeNode *root, vector<int> &v){
    if(root == NULL) return;
    // left right root
    Postorder(root->left,v);
    Postorder(root->right,v);
    v.push_back(root->val);
}

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        Postorder(root, post);
        return post;
    }
};