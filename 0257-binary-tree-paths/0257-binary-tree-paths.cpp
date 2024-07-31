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
    void helper(TreeNode* root ,vector<string> &allPaths,string & curPath){
        if(!root)
        {
            string addPath(curPath);
            allPaths.push_back(addPath);
            return ;
        }
        
        // curPath.push_back(root->val);
        curPath+=to_string(root->val);
        if(!root->left && !root->right)
            helper(root->left,allPaths,curPath);
        if(root->left){
            curPath.push_back('-');
            curPath.push_back('>');
            helper(root->left,allPaths,curPath);
            curPath.pop_back();
            curPath.pop_back();
        }
        if(root->right){
            curPath.push_back('-');
            curPath.push_back('>');
            helper(root->right,allPaths,curPath);
            curPath.pop_back();
            curPath.pop_back();
        }
        curPath.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> allPaths;
        string curPath = "";
        helper(root,allPaths,curPath);
        return allPaths;
    }
};