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
struct CustomComparator {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val >= b->val;  // Reverse the condition for a min-heap
    }
};
class Solution {
public:
    //time : O(NlogN)
    //space : O(NlogN)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*> , CustomComparator> pq;
        for(auto &listH : lists){
            ListNode* curH = listH;
            while(curH){
                ListNode* curN = curH;
                curH = curH->next;
                curN->next = NULL;
                // cout<<curN->val;
                pq.push(curN);
            }
        }
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        while(!pq.empty()){
            tail->next = pq.top();
            tail = tail->next;
            pq.pop();
        }
        return dummy.next;
    }
};