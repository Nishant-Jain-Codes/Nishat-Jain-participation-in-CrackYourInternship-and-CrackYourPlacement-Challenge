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
class Solution {
    ListNode* reverseListRecursive(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* tail = head->next;
        ListNode* newHead = reverseList(tail);
        tail->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode* reverseListIterative(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextt = head->next;
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = nextt;
            if(nextt)
                nextt = nextt->next;
        }
        return prev;
    }
public:
    ListNode* reverseList(ListNode* head) {
        return reverseListIterative(head);
    }
};