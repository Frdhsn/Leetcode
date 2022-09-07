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
    string tree3str(TreeNode* root,TreeNode* r) {
       if(root==nullptr) return "";
        int d = root->val;
        stringstream ss;
        ss<<d;
        string ret="";
        if(r != root) ret = "(";
        ret+=ss.str();
        if(root->left != nullptr && root->right != nullptr){
            ret+=tree3str(root->left,r);
            ret+=tree3str(root->right,r);
        }
        if(root->left != nullptr && root->right == nullptr){
            
            ret+=tree3str(root->left,r);
        }
        if(root->left == nullptr && root->right != nullptr){
            ret+="()";
            ret+=tree3str(root->right,r);
        }
        if(r != root) ret += ")";
        return ret;
    }
    string tree2str(TreeNode* root) {
       
        return tree3str(root,root);
    }
};