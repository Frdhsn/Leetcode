class Solution {
public:
    void go(TreeNode* root,vector<int>&res){
        if(root==nullptr)return;
        res.push_back(root->val);
        go(root->left,res);
        go(root->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        go(root,res);
        return res;
    }
};