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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        if(low<1 || high>1e5)
            return 0;
        int ans = 0;
        if(root->val >= low && root->val <=high)
            ans = root->val;
        ans+= rangeSumBST(root->left , low , min(root->val,high));
        ans+= rangeSumBST(root->right,max(root->val,low),high);
        return ans;
    }
};