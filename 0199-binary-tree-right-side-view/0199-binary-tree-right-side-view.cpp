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
    //last node of every level 
    // Time :O(N)
    // space : O(N);
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        int lastSeenNodeVal = -1;
        queue<TreeNode*> q ;
        q.push(root);
        q.push(NULL);
        vector<int> ans ;
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            if(curNode == NULL){
                if(!q.empty())
                    q.push(NULL);
                ans.push_back(lastSeenNodeVal);
            }
            else{
                lastSeenNodeVal = curNode->val;
                if(curNode->left)
                    q.push(curNode->left);
                if(curNode->right)
                    q.push(curNode->right);
            }
        }
        return ans;

    }
};