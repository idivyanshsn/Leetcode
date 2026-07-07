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
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

public:
    void Inorder(TreeNode* root) {
        if (root == nullptr)
            return;
        Inorder(root->left);
        if (prev != nullptr && (root->val < prev->val)) {
            if (first == nullptr) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;
        Inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        Inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};