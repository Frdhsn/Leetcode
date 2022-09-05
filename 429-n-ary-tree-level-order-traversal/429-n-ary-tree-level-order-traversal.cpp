/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(Node* root, int lvl, map<int,vector<int>>&mp){
        if(root == nullptr)return;
        //cout<<root->val<<" ";
        mp[lvl].push_back(root->val);
        for(auto v:root->children)
            dfs(v,lvl+1,mp);
    }
    vector<vector<int>> levelOrder(Node* root) {
        map<int,vector<int>>mp;
        dfs(root,0,mp);
        vector<vector<int>> res;
        for(auto x:mp){
            vector<int>ret;
            for(auto y:x.second){
                ret.push_back(y);
            }
            res.push_back(ret);
        }
        return res;
    }
};