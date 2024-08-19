/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;
        if(!head->next){
            return new TreeNode(head->val);
        }
        //find mid
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast&&fast->next&&fast->next->next){
            slow = slow->next;
            fast=fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        ListNode* leftPart = head;
        ListNode* rightPart = mid->next;
        mid->next = NULL;
        TreeNode* curNode = new TreeNode(mid->val);
        curNode->left = sortedListToBST(leftPart);
        curNode->right = sortedListToBST(rightPart);
        return curNode;
    }
};