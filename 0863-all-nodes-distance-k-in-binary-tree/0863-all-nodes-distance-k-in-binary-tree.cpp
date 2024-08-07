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
//method 1 , map the parent of every node and then call bfs on target node
    // Time : O(N)
    // Space : O(N)
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_set<TreeNode*> visited;
        unordered_map<TreeNode* , TreeNode*> parent;
        mapParent(root,parent);
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        visited.insert(target);
        vector<int> answer;
        while(!q.empty()){
            TreeNode* curNode = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(dist == k){
                answer.push_back(curNode->val);
            }
            else{
                if(parent.find(curNode)!=parent.end() && visited.find(parent[curNode]) == visited.end()) {
                    visited.insert(parent[curNode]);
                    q.push({parent[curNode],dist+1});
                }
                if(curNode->left && visited.find(curNode->left)==visited.end())
                    {
                        visited.insert(curNode->left);
                        q.push({curNode->left,dist+1});
                    }
                if(curNode->right && visited.find(curNode->right)==visited.end())
                    {
                        visited.insert(curNode->right);
                        q.push({curNode->right,dist+1});
                    }
            }

        }
        return answer;
    }
    private:
    void mapParent(TreeNode* root , unordered_map<TreeNode*,TreeNode*> &parent)
        {
            if(!root)
                return ;
            if(root->left)
                parent[root->left] = root;
            if(root->right)
                parent[root->right] = root;
            mapParent(root->left,parent);
            mapParent(root->right,parent);
        }
};