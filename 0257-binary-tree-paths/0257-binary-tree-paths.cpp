/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void function(TreeNode* root, vector<string>& ans, string path) {
        if (root == nullptr)
            return;
        path += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
        } else {
            path += "->";
            function(root->left, ans, path);
            function(root->right, ans, path);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == nullptr)
            return ans;
        function(root, ans, "");
        return ans;
    }
};