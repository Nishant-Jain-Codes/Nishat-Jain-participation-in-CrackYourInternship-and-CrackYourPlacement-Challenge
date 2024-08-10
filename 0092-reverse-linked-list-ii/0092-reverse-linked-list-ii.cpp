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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(-1,head);
        ListNode* tail = &dummy;
        // tail->next = head;
        // tail=tail->next;
        int curLoc = 1;
        while(tail->next && curLoc!=left){
            tail=tail->next;
            curLoc++;
        }
        ListNode* tail2 = tail;
        int curLoc2 = curLoc;
        while(tail2->next && curLoc2<=right){
            tail2=tail2->next;
            curLoc2++;
        }
        ListNode* revStart = tail->next;
        tail->next = NULL;
        ListNode* revEnd = tail2->next;
        tail2->next = NULL;
        pair<ListNode*,ListNode*> sol = reverse(revStart);
        tail->next = sol.first;
        sol.second->next = revEnd;
        return dummy.next;
    }
private: 
    pair<ListNode*,ListNode*> reverse(ListNode* head){
        if(!head||!head->next)
            return {head,head};
        ListNode* tail = head->next; 
        pair<ListNode*,ListNode*> sol = reverse(head->next);
        sol.second->next = head;
        head->next = NULL;
        ListNode* newTail = head;
        ListNode* newHead = sol.first;
        return {newHead,newTail};
    }
};