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
    map<int,int>mp;
    void find(TreeNode* root){
        if(root == nullptr){
            return;
        }
        mp[root->val] = 1;
        find(root->left);
        find(root->right);
    }
    bool find2(TreeNode* root, int k){
        if(root == nullptr){
            return false;
        }
        int curr = root->val; 
        int need = k-curr;
        if( curr!=need && mp[need])return true;
        if(find2(root->left,k))
            return true;
        if(find2(root->right,k))
            return true;
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        find(root);
        return find2(root,k);
    }
};