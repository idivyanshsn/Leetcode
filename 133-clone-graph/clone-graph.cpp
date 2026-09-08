/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* curr,unordered_map<Node*,Node*>& mpp){
        if(mpp.count(curr)) return mpp[curr];
        Node* copy = new Node(curr->val);
        mpp[curr]=copy;
        for(Node* nod:curr->neighbors){
            copy->neighbors.push_back(dfs(nod,mpp));
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mpp;
        if(node==NULL) return nullptr;
        return dfs(node,mpp);
    }
};