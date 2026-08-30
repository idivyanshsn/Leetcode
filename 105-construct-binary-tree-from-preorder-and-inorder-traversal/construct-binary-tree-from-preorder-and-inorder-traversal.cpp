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
    int preIndex=0;
    TreeNode* function(vector<int>& preorder, vector<int>& inorder,int start,int end,unordered_map<int,int>& mpp){
        if(start>end) return nullptr;
        int rootVal=preorder[preIndex++];
        TreeNode* root=new TreeNode(rootVal);
        int mid=mpp[rootVal];
        root->left=function(preorder,inorder,start,mid-1,mpp);
        root->right=function(preorder,inorder,mid+1,end,mpp);

        return root;
        }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        for(int i=0;i<inorder.size();i++)
            mpp[inorder[i]]=i;
        return function(preorder,inorder,0,inorder.size()-1,mpp);
    }
};