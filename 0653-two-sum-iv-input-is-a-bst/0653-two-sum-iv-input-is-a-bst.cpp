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
    void traverse(TreeNode* root, vector<int>& arr) {
        if (root == nullptr)
            return;
        traverse(root->left,arr);
        arr.push_back(root->val);
        traverse(root->right,arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        traverse(root, arr);
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]+arr[j]==k){
                    return true;
                    break;
                }
            }
        }
        return false;
    }
};