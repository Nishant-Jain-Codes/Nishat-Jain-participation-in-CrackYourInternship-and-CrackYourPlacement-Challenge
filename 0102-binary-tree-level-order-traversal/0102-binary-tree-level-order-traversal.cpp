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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> curLevel ;
        vector<vector<int>> traversal;
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            if(curNode==NULL){
                traversal.push_back(curLevel);
                curLevel.clear();
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                curLevel.push_back(curNode->val);
                if(curNode->left)
                    q.push(curNode->left);
                if(curNode->right)
                    q.push(curNode->right);
            }
        }
        return traversal;
    }
};