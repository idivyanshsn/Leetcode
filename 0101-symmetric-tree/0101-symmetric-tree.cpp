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
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || function(root->left,root->right);
    }
    bool function(TreeNode* left, TreeNode* right){
        if(left==nullptr || right==nullptr){
            return left==right;
        }
        if(left->val!=right->val) return false;
        return function(left->left,right->right) && function(left->right,right->left);
    }
};