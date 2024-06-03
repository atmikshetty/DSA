class Solution{
    public:
    vector<int> topView(TreeNode* root){
        vector<int> ans;
        if(root == NULL) return ans;
        map<int,int> mpp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int column = it.second;
            if(mpp.find(column) == mpp.end()) mpp[column] = node -> val;
            if(node-> left != NULL){
                q.push({node->left, column-1});
            }
            if(node->right != NULL){
                q.push({node->right, column+1});
            }
        }

        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};