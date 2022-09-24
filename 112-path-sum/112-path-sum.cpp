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
    int dfs(TreeNode* root, int targetSum){
        if(root == nullptr)return 0;
        if(root->left == nullptr && root->right == nullptr){
            return targetSum==(root->val);
        }
        int val = root->val;
        return dfs(root->left,targetSum-val) or dfs(root->right,targetSum-val); 
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,targetSum);
    }
};