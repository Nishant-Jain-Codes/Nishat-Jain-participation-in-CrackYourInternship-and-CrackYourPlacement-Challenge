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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s ; 
        for(auto &x:nums)
            s.insert(x);
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        while(head){
            if(s.find(head->val)==s.end()){
                tail->next = head;
                tail = tail->next;
            }
            head = head->next;
        }
        tail->next = NULL;
        return dummy.next;
    }
};