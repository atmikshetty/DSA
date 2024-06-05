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
public:
    int countNodes(TreeNode* root) {
        // vector<int> ans;
        // inorder(root, ans);
        // return ans.size();

        if(root == NULL) return 0;

        int lh = findLeft(root);
        int rh = findRight(root);

        if(lh == rh) return(1<<lh) - 1;  // 2^n

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findLeft(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root -> left;
        }
        return height;
    }

    int findRight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root -> right;
        }
        return height;
    }

    void inorder(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
};