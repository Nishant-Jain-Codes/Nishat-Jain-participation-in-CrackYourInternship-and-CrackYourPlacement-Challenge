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
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        vector<vector<int>> answer ;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int curLevelSize = q.size();
            vector<int> curLevel;
            for(int i = 0;i<curLevelSize;i++){
                Node* curNode = q.front();
                q.pop();
                curLevel.push_back(curNode->val);
                for(int j = 0 ; j<curNode->children.size();j++)
                    q.push(curNode->children[j]);
            }
            answer.push_back(curLevel);
        }
        return answer;
    }
};