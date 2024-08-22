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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)  
            return {};
        vector<int> cur = postorderTraversal(root->left);
        // cur.insert(cur.end(),left.begin(),left.end());
        vector<int> right = postorderTraversal(root->right);
        
        cur.insert(cur.end(),right.begin(),right.end());
        cur.push_back(root->val);
        return cur;
    }
};