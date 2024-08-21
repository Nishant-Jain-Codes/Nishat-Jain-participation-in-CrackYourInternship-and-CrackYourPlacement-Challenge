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
public:
    ListNode* insertGreatestCommonDivisors(ListNode* h) {
        ListNode* head = h;
        if(!head || !head->next)
            return head;
        int i = 0;
        ListNode* tail = h;
        head = head->next;
        while(head){
            tail->next = new ListNode(gcd(tail->val,head->val));
            tail = tail->next;
            tail->next = head;
            head = head->next;
            tail = tail->next;
        }
        return h;
    }
};