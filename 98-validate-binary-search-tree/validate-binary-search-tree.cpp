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
    bool function(TreeNode* root,long long minVal, long long maxVal){
        if(root==nullptr) return true;
        if(root->val>=maxVal || root->val<=minVal) return false;
        return function(root->left,minVal,root->val) && function(root->right,root->val,maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return function(root,LONG_LONG_MIN,LONG_LONG_MAX);
    }
};