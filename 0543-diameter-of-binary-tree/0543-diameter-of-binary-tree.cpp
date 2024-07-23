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
    pair<int,int> postorder(TreeNode* root){
        if(!root)   
            return {0,0};
        pair<int,int> leftAns = postorder(root->left);
        pair<int,int> rightAns = postorder(root->right);
        int curHeight = max(leftAns.first,rightAns.first) +1;
        int curDiameter = max({(leftAns.first+rightAns.first),leftAns.second,rightAns.second});
        return {curHeight,curDiameter};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return postorder(root).second;
    }
};