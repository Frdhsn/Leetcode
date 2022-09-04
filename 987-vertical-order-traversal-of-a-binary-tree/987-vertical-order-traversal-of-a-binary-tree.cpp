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
    void dfs(TreeNode* root,int r,int c,vector<pair<pair< int,int>,int>> &verticalOrder){
        if(root == nullptr){
            return;
        }
        verticalOrder.push_back({{c,r},root->val});
        dfs(root->left,r+1,c-1,verticalOrder);
        dfs(root->right,r+1,c+1,verticalOrder);        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<pair< int,int>,int>> verticalOrder;
        vector<vector<int>> res;
        dfs(root,0,0,verticalOrder);
        sort(verticalOrder.begin(),verticalOrder.end());
        int id=INT_MIN;
        vector<int>ret;
        map<int,vector<int>>mp;
        for(auto x:verticalOrder){
            mp[x.first.first].push_back(x.second);
        }
        for(auto x:mp){
            vector<int>ret;
            for(auto y:x.second)
            {
                ret.push_back(y);
                
            }
            res.push_back(ret);
        }
        return res;
    }
};