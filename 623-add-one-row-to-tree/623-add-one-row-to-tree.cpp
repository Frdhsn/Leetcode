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
    void dfs(TreeNode* u,int depth,int val){
        if(u== nullptr)return;
        //cout<<(u->val)<<" "<<depth<<endl;
        if(depth == 1 && (u->left != nullptr or u->right != nullptr)){
            //if(u->left != nullptr){
                TreeNode *tmp = new TreeNode(val);
                tmp->left = u->left;
                u->left = tmp;
            //}
            //if(u->right != nullptr){
                
                TreeNode *tmp2 = new TreeNode(val);
                tmp2->right = u->right;
                u->right = tmp2;
            //}
            return;
        }
        if(depth<=1 && u->left == nullptr&& u->right == nullptr){
                TreeNode *tmp = new TreeNode(val);
                u->left = tmp;
                TreeNode *tmp2 = new TreeNode(val);
                u->right = tmp2;
            
            return;
        }
        dfs(u->left,depth-1,val);
        dfs(u->right,depth-1,val);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *tmp = new TreeNode(val);
            tmp->left = root;
            return tmp;
        }
        dfs(root,depth-1,val);
        return root;
    }
};