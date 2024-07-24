//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
using namespace std;
class Solution{
  public:
    void traversal(Node * root , vector<int> & inorder){
        if(!root)
            return ;
        traversal(root->left,inorder);
        int valAdd = root->data;
        if(!root->left && !root->right) //mark node as leaf
            valAdd *=-1;
        inorder.push_back(valAdd);
        traversal(root->right,inorder);
        
        
    }
    bool isDead(vector<int>& inorder , int curVal,int curIdx){
        int n = inorder.size()-1;
        if(curVal == 1 && curIdx+1<=n && inorder[curIdx+1]==2)
            return true;
        if(curVal == 10001 && curIdx-1>=0 && inorder[curIdx-1]==10000)
            return true;
        if(curIdx+1<=n && curIdx-1>=0 && inorder[curIdx+1]==curVal+1 && inorder[curIdx-1]==curVal-1)
            return true;
        return false;
    }
    bool isDeadEnd(Node *root)
    {
        //Your code here
        vector<int> inorder;
        traversal(root,inorder);
        for(int i = 0;i<inorder.size();i++){
            // cout<<inorder[i]<<" ";
            int curVal = inorder[i];
            bool isLeaf = false;
            if(curVal<0){
                isLeaf = true;
                curVal*=-1;
            }
            if(isLeaf)
            {
                // cout<<curVal<<" is leaf"<<endl;
                if(isDead(inorder,curVal,i))
                    {
                        // cout<<curVal<<" is a dead end"<<endl;
                        return true;
                    }
            }
        }
        
        // cout<<endl;
        return false;
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends