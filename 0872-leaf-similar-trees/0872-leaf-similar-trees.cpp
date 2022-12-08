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
    void dfs(TreeNode* root, vector<int>&ar){
        if(root == nullptr)return;
        if(root->left == nullptr && root->right == nullptr){
            ar.push_back(root->val);
            return;
        }
        dfs(root->left,ar);
        dfs(root->right,ar);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1,leaves2;
        dfs(root1,leaves1);
        dfs(root2,leaves2);
        return leaves1==leaves2;
    }
};