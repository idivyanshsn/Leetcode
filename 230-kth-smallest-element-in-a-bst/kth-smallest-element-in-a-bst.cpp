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
    void function(vector<int>& result, TreeNode* root){
        if(root==nullptr) return;
        function(result,root->left);
        result.push_back(root->val);
        function(result,root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        function(result,root);
        return result[k-1];
    }
};