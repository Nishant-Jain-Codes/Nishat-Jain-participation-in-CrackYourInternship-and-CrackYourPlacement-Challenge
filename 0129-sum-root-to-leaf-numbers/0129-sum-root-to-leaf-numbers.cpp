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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        helper(root,ans,0);
        return ans;
    }
private :
    void helper(TreeNode* root , int &ans,int curPath){
        if(!root)
            return ;
        curPath = curPath*10 + root->val;
        if(!root->right && !root->left)
            {
                ans+= curPath;
                return ;
            }
        helper(root->left,ans,curPath);
        helper(root->right,ans,curPath);
    }
};