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
    //space :O(N)
    ListNode* mergeNodes(ListNode* head) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        int curCount = 0;
        while(head){
            if(head->val == 0 && curCount!=0){
                    ListNode* addNode = new ListNode(curCount,head);
                    tail->next = addNode;
                    tail=tail->next;
                    curCount=0;
            }
            else{
                curCount += head->val;
            }
            head=head->next;
        }
        tail->next = NULL;
        return dummy.next;
    }
};