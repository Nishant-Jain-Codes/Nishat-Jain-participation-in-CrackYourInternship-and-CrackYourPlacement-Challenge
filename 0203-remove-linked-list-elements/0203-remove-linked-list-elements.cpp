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
    //iterative
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0,head);
        ListNode* prev = &dummy;
        for(ListNode* temp= head ; temp!=NULL;temp=temp->next){
            if(temp->val!=val){
                prev->next = temp;
                prev = prev->next;
            }
        }
        prev->next = NULL;
        return dummy.next;
    }
    // ListNode* removeElements(ListNode* head, int val) {
    //     if(!head)
    //         return NULL;
        
    //     if(head->val == val){
    //         ListNode* del = head;
    //         head=head->next;
    //         del->next = NULL;
    //         delete del;
    //         return removeElements(head,val);
    //     }
    //     else
    //         {
    //             head->next = removeElements(head->next,val);
    //             return head;
    //         }
    // }
};