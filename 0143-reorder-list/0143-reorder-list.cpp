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
    // method 2 : find mid of list , split the list there , then join one after other elements of the list
    void reorderList(ListNode* head) {
            head = method1(head);
    }
private: 
    // method 1 : call reverse list on the head'next , time n^2
    ListNode* method1(ListNode* head) {
        if(!head||!head->next)
            return head;
        head->next = reverse(head->next);
        head->next = method1(head->next);
        return head;
    }
    ListNode* reverse(ListNode* head){
        if(!head || !head->next)
            return head;
        ListNode* tail = head->next ; 
        ListNode * newHead = reverse(head->next);
        tail->next = head;
        head->next = NULL;
        return newHead;
    }
};