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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummyH(-1);
        ListNode* dummyT = &dummyH;
        while(head){
            if(!head->next || head->val != head->next->val){
                dummyT->next = head;
                dummyT = dummyT->next;
            }
            else{
                while(head->next && head->val == head->next->val )
                    head = head->next;
            }
            head = head->next;
        }    
        dummyT->next = NULL;
        return dummyH.next;
    }
};