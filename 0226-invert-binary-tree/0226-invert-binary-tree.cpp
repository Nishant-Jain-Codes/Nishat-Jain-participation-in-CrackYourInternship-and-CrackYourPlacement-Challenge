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
    // time  : O(N)
    // space : O(H)
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        TreeNode* rightRec = invertTree(root->right);
        TreeNode* leftRec = invertTree(root->left);
        root->left = rightRec;
        root->right = leftRec;
        return root;
    }
};