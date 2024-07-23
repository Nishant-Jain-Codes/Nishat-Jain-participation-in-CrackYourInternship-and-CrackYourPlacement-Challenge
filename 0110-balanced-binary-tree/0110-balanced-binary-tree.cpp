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
    //space : O(H)
    pair<int,int> helper(TreeNode* root){
        if(!root)
            return {0,true};
        pair<int,int> leftAns = helper(root->left);
        pair<int,int> rightAns = helper(root->right);
        bool isBalanced = (abs(leftAns.first-rightAns.first)<=1 && leftAns.second && rightAns.second);
        int curHeight = max(leftAns.first,rightAns.first)+1;
        return {curHeight,isBalanced};
    }
    bool isBalanced(TreeNode* root) {
        return helper(root).second;
    }
};