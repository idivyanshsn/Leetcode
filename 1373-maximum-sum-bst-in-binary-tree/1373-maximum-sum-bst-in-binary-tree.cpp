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
class NodeValue {
public:
    int min, max, sum;
    NodeValue(int min, int max, int sum) {
        this->max = max;
        this->min = min;
        this->sum = sum;
    }
};
class Solution {
public:
    int fin_sum = 0;
    NodeValue function(TreeNode* root) {
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, 0);
        auto left = function(root->left);
        auto right = function(root->right);
        if ((left.max < root->val) && (right.min>root->val)){
                int curr_sum = left.sum + right.sum + root->val;
                fin_sum = max(fin_sum, curr_sum);

                return NodeValue(min(root->val, left.min),
                                 max(root->val, right.max), curr_sum);
            }
        return NodeValue(INT_MIN, INT_MAX, 0);
    }
    int maxSumBST(TreeNode* root) {
        fin_sum = 0;
        function(root);
        return fin_sum;
    }
};