class Solution{
    public:
    vector<int> bottomView(TreeNode* root){
        vector<int> ans;
        if(root == NULL) return ans;
        map<int,int> mpp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front();
            TreeNode* root = it.first;
            int col = it.second;
            mpp[col] = root->data;

            if(root->left != NULL){
                q.push({root->left, col-1});
            }
            if(root->right != NULL){
                q.push({root->right, col+1});
            }
        }
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};