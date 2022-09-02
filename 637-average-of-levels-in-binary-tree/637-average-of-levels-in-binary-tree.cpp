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
    vector<double>ar[100007];
    int sz=0;
    void dfs(TreeNode *root, int depth){
        if(root==nullptr)return;
        sz = max(sz,depth);
        ar[depth].push_back(root->val);
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
    double sum(vector<double>a){
        double s=0.0;
        for(auto x:a)s+=x;
        return s;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root,0);
        vector<double>res(sz+1);
        for(int i=0;i<=sz;i++){
            int sz_ar = ar[i].size();
            res[i]=(double)(sum(ar[i])/(sz_ar*1.0));
        }
        return res;
    }
};