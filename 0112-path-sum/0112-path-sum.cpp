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
    // Time : O(N)
    // Space : O(H)
    bool helper(TreeNode* root,int targetSum ,int curSum){
        if(!root)
            return false;
        if((curSum + root->val )==targetSum && (!root->left && !root->right))
            return true;
        return helper(root->right,targetSum,curSum+root->val) || helper(root->left,targetSum,curSum+root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,targetSum,0);
    }
};