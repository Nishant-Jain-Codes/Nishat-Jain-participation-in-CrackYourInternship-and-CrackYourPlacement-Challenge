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
    //time : O(N)
    //space : O(1)
    ListNode* deleteMiddle(ListNode* head) {
     if(!head||!head->next)
        return NULL;
     ListNode* slow = head;
     ListNode* fast = head->next;
     while(fast && fast->next && fast->next->next){
        slow = slow->next;
        fast=fast->next->next;
     }    
     cout<<slow->val<<endl;
     slow->next = slow->next->next;
     return head;
    }
};