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
    void function(TreeNode* root,vector<int>& result){
        if(root==nullptr){
            result.push_back(INT_MIN);
            return;
        }
        result.push_back(root->val);
        function(root->left,result);
        function(root->right,result);

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> parr;
        vector<int> qarr;
        function(p,parr);
        function(q,qarr);
        return parr==qarr;
    }
};