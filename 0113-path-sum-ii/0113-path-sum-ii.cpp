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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> curPath;
        int curSum = 0;
        dfs(curSum,root,targetSum,curPath,allPaths);
        return allPaths;
    }
private:    
    void dfs(int curSum , TreeNode* root , const int &targetSum,vector<int>&curPath , vector<vector<int>>& allPaths){
        if(!root)
            return ;
        curSum+=root->val;
        curPath.push_back(root->val);
        if(curSum==targetSum &&!root->left && !root->right){
            cout<<"path found"<<endl;
            allPaths.push_back(curPath);
            // return;
        }
        else{
            dfs(curSum,root->left,targetSum,curPath,allPaths);
            dfs(curSum,root->right,targetSum,curPath,allPaths);
        }
        // curSum-=root->val;
        curPath.pop_back();
    }
};