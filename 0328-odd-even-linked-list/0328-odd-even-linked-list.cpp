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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!head->next->next)
            return head;
        ListNode * oddH = new ListNode(-1);
        ListNode * evenH = new ListNode(-1);
        ListNode * oddT = head;
        oddH->next = oddT;
        ListNode * evenT = head->next;
        evenH->next = evenT;
        // head=head->next->next;
        while(oddT && oddT->next){
            oddT->next =evenT->next;
            oddT= oddT->next;
            // if(!oddT)
            //     break;
            evenT->next = oddT->next;
            evenT=evenT->next;
            // if(!evenT)
            //     break;
        }
        oddT->next = evenH->next;
        if(evenT)
            evenT->next = NULL;
        return oddH->next;
    }
};