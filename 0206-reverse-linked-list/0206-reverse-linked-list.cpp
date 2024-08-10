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
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while (curr) {
        ListNode* nextNode = curr->next; // Store the next node
        curr->next = prev;               // Reverse the link
        prev = curr;                     // Move prev forward
        curr = nextNode;                 // Move curr forward
    }
    
    return prev;
}

public:
    ListNode* reverseList(ListNode* head) {
        return reverseListIterative(head);
    }
};