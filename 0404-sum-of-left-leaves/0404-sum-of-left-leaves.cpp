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
    //time : O(N)
    //space : O(N)
    int helper(TreeNode* root,char dir){
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return dir=='L'?root->val:0;
        return helper(root->left,'L')+helper(root->right,'R');
    }   
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root,'R');
    }
};