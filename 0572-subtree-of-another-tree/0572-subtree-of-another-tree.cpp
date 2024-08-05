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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)
            return true;
        if(!root||!subRoot)
            return false;
        bool ans = false;
        if(root->val == subRoot->val)
            ans |= (isSame(root->right,subRoot->right) && isSame(root->left,subRoot->left));
        ans |= isSubtree(root->right,subRoot) || isSubtree(root->left,subRoot);
        return ans;
        
    }
private : 
    bool isSame(TreeNode* r1 , TreeNode* r2){
        if(r1 == NULL || r2==NULL)
            return r1 ==r2;
        if(r1->val == r2->val)
            return isSame(r1->left,r2->left) && isSame(r1->right,r2->right);
        return false;
    }
};