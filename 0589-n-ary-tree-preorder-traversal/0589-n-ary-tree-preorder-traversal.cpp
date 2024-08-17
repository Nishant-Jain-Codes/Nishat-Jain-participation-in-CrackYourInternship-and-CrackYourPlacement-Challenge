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
    //time  : O(N)
    //space : O(N)
    vector<int> preorder(Node* root) {
        vector<int> traversal;
        traverse(root,traversal);
        return traversal;
    }
private : 
    void traverse(Node* root , vector<int> & traversal){
        if(!root)
            return;
        traversal.push_back(root->val);
        for(auto &c : root->children)
            traverse(c,traversal);
    }
};