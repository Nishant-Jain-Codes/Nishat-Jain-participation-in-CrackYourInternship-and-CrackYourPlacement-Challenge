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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return builder(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);    
    }
private:
    TreeNode* builder(vector<int>& post,int pS,int pE,vector<int>& ino,int iS,int iE){
        if(pS>pE)
            return NULL;
        if(pS==pE)
            return new TreeNode(post[pE]);
        int rootVal = post[pE];
        TreeNode* root = new TreeNode(rootVal);
        int rootIndexInInorder;
        int i = iS;
        while(i<=iE)
        {
            if(ino[i]==rootVal)
                break;
            i++;
        }
        rootIndexInInorder = i;
        // cout<<rootIndexInInorder<<" "<<ino[rootIndexInInorder]<<" "<<rootVal<<endl;
        int iSL = iS;
        int iEL = rootIndexInInorder-1;
        int leftSubtreeSize = iEL-iSL+1;
        int iSR = rootIndexInInorder+1;
        int iER = iE;
        int pSL = pS;
        int pEL = pSL+leftSubtreeSize-1;
        int pSR = pEL + 1;
        int pER = pE-1;
        root->left = builder(post,pSL,pEL,ino,iSL,iEL);
        root->right = builder(post,pSR,pER,ino,iSR,iER);
        return root;
    }
};