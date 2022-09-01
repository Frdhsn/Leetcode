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
    int ret;
    void dfs(TreeNode* root,int mx){
        if(root==NULL)return;
        int x = root->val;
        if(x>=mx)ret++;
        dfs(root->left , max(mx,x));
        dfs(root->right , max(mx,x));
    }
    int goodNodes(TreeNode* root) {
        ret=0;
        dfs(root,-1e9);
        return ret;
    }
};