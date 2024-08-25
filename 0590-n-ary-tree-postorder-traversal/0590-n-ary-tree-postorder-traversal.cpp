/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> traversal;
        traverse(root,traversal);
        return traversal;
    }
   void traverse(Node* root , vector<int> & traversal){
        if(!root)
            return;
        for(auto &c : root->children)
            traverse(c,traversal);
        traversal.push_back(root->val);
    }
};