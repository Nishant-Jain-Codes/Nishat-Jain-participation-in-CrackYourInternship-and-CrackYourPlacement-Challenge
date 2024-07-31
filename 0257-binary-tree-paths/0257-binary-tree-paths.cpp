class Solution {
public:
    void helper(TreeNode* root, vector<string>& allPaths, string curPath) {
        if (!root) return;

        if (!curPath.empty()) {
            curPath += "->";
        }
        curPath += to_string(root->val);

        if (!root->left && !root->right) {
            allPaths.push_back(curPath);
        } else {
            if (root->left) helper(root->left, allPaths, curPath);
            if (root->right) helper(root->right, allPaths, curPath);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> allPaths;
        if (root) {
            helper(root, allPaths, "");
        }
        return allPaths;
    }
};
