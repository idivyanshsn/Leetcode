/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_map;
        mapParents(root, nullptr, parent_map);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int current_layer = 0;
        while (!q.empty()) {
            if (current_layer == k) {
                vector<int> result;
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* current = q.front();
                q.pop();
                if (current->left && !visited.count(current->left)) {
                    visited.insert(current->left);
                    q.push(current->left);
                }
                if (current->right && !visited.count(current->right)) {
                    visited.insert(current->right);
                    q.push(current->right);
                }
                TreeNode* parent = parent_map[current];
                if (parent && !visited.count(parent)) {
                    visited.insert(parent);
                    q.push(parent);
                }
            }
            current_layer++;
        }

        return {};
    }

private:
    void mapParents(TreeNode* node, TreeNode* parent,
                    unordered_map<TreeNode*, TreeNode*>& map) {
        if (!node)
            return;
        map[node] = parent;
        mapParents(node->left, node, map);
        mapParents(node->right, node, map);
    }
};
