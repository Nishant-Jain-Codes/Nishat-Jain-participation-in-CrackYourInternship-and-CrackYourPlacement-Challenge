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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        stack<ListNode*> stk;
        while(fast!=NULL && fast->next!=NULL){
            stk.push(slow);
            slow = slow->next;
            fast=fast->next->next;
        }
        // cout<<stk.size();
        if(fast!=NULL)
            slow = slow->next;
        while(slow!=NULL){
            ListNode* cur = stk.top();
            stk.pop();
            // cout<<cur->val<<" "<<slow->val<<endl;
            if(cur->val != slow->val)
                return false;
            slow=slow->next;
        }
        return true;
    }
};