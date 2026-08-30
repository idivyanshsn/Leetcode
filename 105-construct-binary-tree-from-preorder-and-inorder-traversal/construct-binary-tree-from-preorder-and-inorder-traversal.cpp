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
    TreeNode* function(vector<int>& preorder, vector<int>& inorder,int start,int end ){
        if(start>end) return nullptr;
        int rootVal=preorder[preIndex++];
        TreeNode* root=new TreeNode(rootVal);
        int mid=find(inorder.begin(),inorder.end(),rootVal)-inorder.begin();
        root->left=function(preorder,inorder,start,mid-1);
        root->right=function(preorder,inorder,mid+1,end);

        return root;
        }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return function(preorder,inorder,0,preorder.size()-1);
    }
};