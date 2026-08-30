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
    string ans="";
    void dfs(TreeNode* root,string path){
        if(root==nullptr) return;
        path+=char('a'+ root->val);
        if(root->left==nullptr && root->right==nullptr) {
            reverse(path.begin(),path.end());
            if(ans=="" || path<ans){
                ans=path;
            }
            return;
        }
        dfs(root->left,path);
        dfs(root->right,path);
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
};