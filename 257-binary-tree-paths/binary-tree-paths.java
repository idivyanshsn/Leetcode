/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public void  function(TreeNode root,List<String>ans,String path ){
        if(root==null) {
            return ;
        }
        path+=root.val;
        if(root.left==null && root.right == null ) ans.add(path);
        else{
            path+="->";
            function(root.left,ans,path);
            function(root.right,ans,path);
        }
    }
    public List<String> binaryTreePaths(TreeNode root) {
        ArrayList<String> ans = new ArrayList<>();
        if(root==null){
            return ans;
        }
        function(root,ans,"");
        return ans;
    }
}