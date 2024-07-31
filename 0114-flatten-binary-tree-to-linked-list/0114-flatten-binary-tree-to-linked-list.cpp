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
    TreeNode* helper(TreeNode * root){

        if(!root)
            return NULL;
        TreeNode* leftRec = helper(root->left);
        TreeNode* rightRec = helper(root->right);
        root->left = NULL;
        root->right = leftRec;
        TreeNode* temp = root;
        while(temp->right!=NULL)
            temp = temp->right;
        temp->right = rightRec;
        return root;
    }
    void flatten(TreeNode* root) {
        helper(root);
    }
};