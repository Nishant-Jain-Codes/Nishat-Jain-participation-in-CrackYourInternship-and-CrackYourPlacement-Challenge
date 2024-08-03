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
    // getting boundary issue 
    vector<int> helper(TreeNode* root){
        if(!root)
            return {true,INT_MIN,INT_MAX}; //<isValid , max , min>
        if(!root->left && !root->right)
            return {true,root->val,root->val}; 
        bool isValid = true; 
        int minVal = root->val;
        int maxVal = root->val;
        if(root->left)
            {
                vector<int> leftRec = helper(root->left);
                isValid = isValid && root->val > leftRec[1] && leftRec[0];
                minVal = leftRec[2];
            }
        if(root->right)
            {
                vector<int> rightRec = helper(root->right);
                isValid = isValid && root->val < rightRec[2] && rightRec[0];
                maxVal = rightRec[1];
            }
        return {isValid,maxVal,minVal};
    }
    bool isValidBST(TreeNode* root) {
        return helper(root)[0];
    }
};