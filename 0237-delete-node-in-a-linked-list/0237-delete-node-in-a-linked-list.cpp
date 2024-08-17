/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // time : O(1)
    // space : O(1)
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node->next;
        node->next = NULL;
        node->val = nextNode->val;
        node->next = nextNode->next;
        nextNode->next = NULL;
        delete nextNode;
    }
};