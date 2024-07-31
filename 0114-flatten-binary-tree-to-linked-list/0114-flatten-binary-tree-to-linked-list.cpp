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
    //space : O(N)
    //inplace changing
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
    //Time : O(N)
    //Space : O(1)
    //move the left substree to the right , by changing the pointers
    void optimisedIterative(TreeNode* givenRoot){
        TreeNode* root = givenRoot;
        while(root){
            if(root->left){
                TreeNode* rightMost = root->left;
                while(rightMost->right)
                    rightMost=rightMost->right;
                rightMost->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root=root->right;
        }
    }
    void flatten(TreeNode* root) {
        // helper(root);
        optimisedIterative(root);
    }
};