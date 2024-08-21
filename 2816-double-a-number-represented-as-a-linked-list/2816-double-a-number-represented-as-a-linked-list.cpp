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
    ListNode* doubleIt(ListNode* head) {
        ListNode* prev = NULL;
        int carry = 0;
        helper(head,carry);
        if(carry)
        {
            ListNode* newHead = new ListNode(carry);
            newHead ->next = head;
            head = newHead;
        }
        return head;
    }
private: 
    void helper(ListNode* cur,int & carry){
        if(!cur)
            return ;
        helper(cur->next,carry);
        int val = 2*(cur->val) + carry;
        carry = val/10;
        val = val%10;
        cur->val = val;
        // return cur;
    }
};