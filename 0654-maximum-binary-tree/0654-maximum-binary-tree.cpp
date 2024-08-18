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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(0,nums.size()-1,nums);
    }
private: 
    TreeNode* helper(int si,int ei , vector<int> & nums){
        if(si>ei)
            return NULL;
        int maxIdx = si;
        for(int i = si;i<=ei;i++){
            if(nums[i]>nums[maxIdx])
                maxIdx=i;
        }
        TreeNode* newNode = new TreeNode(nums[maxIdx]);
        newNode->left = helper(si,maxIdx-1,nums);
        newNode->right = helper(maxIdx+1,ei,nums);
        return newNode;
    }
};