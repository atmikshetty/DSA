/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void PreOrder(TreeNode *root, vector<int>& v){
    if(root == NULL) return;
    // root left right
    v.push_back(root->data);
    PreOrder(root->left,v);
    PreOrder(root->right,v);
}

void InOrder(TreeNode *root, vector<int> &v){
    if(root == NULL) return;
    // left root right
    InOrder(root->left,v);
    v.push_back(root->data);
    InOrder(root->right,v);
}

void PostOrder(TreeNode *root, vector<int> &v){
    if(root==NULL) return;
    // left right root
    PostOrder(root->left,v);
    PostOrder(root->right, v);
    v.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int> inorder;
    vector<int> pre;
    vector<int> post;
    vector<vector<int>> v;

    InOrder(root, inorder);
    PreOrder(root, pre);
    PostOrder(root, post);

    v.push_back(inorder);
    v.push_back(pre);
    v.push_back(post);
    return v;
}