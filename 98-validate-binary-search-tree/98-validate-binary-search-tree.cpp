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
    using ll = long long;
    bool bad;
    pair<ll,ll> go(TreeNode* root){
        if(root == nullptr){
            return {1e12,-1e12};
        }
        auto l = go(root->left);
        if(l.second >= root->val && l.second!=1e12){
            bad = true;
        }
        auto r = go(root->right);
        if(r.first <= root->val && r.first!= -1e12){
            bad = true;
        }
        //cout<<"curr: "<<root->val<<"\n";
       // cout<<"left : ("<<l.first<<","<<l.second<<")\n";
       // cout<<"right : ("<<r.first<<","<<r.second<<")\n";
        return {min({l.first,r.first,(ll)root->val}),max({(ll)root->val,l.second,r.second})};
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)return true;
        if(root->left == nullptr&&root->right==nullptr)return true;
        bad = false;
        go(root);
        return bad==false;
    }
};