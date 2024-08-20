/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        vector<Node*> curLevel ; 
        queue<Node*> q ; 
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* curNode = q.front();
            q.pop();
            if(curNode==NULL){
                cout<<" s-> "<<curLevel.size()<<" ";
                Node* head = curLevel[0];
                for(int i = 1;i<curLevel.size();i++){
                    head->next = curLevel[i];
                    head = head->next;
                }
                curLevel.clear();
                if(!q.empty())
                    q.push(NULL);
                cout<<endl;
            }
            else{
            cout<<curNode->val<<" ";
            // if(!curNode)
            //     {
            //         cout<<"NULL issue";
            //         break;
            //     }
                curLevel.push_back(curNode);
                if(curNode->left)
                    q.push(curNode->left);
                if(curNode->right)
                    q.push(curNode->right);
            }
        }
        return root;
    }
};