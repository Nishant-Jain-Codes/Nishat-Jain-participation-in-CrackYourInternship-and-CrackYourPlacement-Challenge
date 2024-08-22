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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return builder(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);    
    }
private:
    TreeNode* builder(vector<int>& pre,int pS,int pE,vector<int>& ino,int iS,int iE){
        if(pS>pE)
            return NULL;
        if(pS==pE)
            return new TreeNode(pre[pS]);
        int rootVal = pre[pS];
        TreeNode* root = new TreeNode(rootVal);
        int rootIndexInInorder;
        int l = iS;
        int r = iE;
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
        int pSL = pS+1;
        int pEL = pSL+leftSubtreeSize-1;
        int pSR = pEL + 1;
        int pER = pE;
        root->left = builder(pre,pSL,pEL,ino,iSL,iEL);
        root->right = builder(pre,pSR,pER,ino,iSR,iER);
        return root;
    }
};

