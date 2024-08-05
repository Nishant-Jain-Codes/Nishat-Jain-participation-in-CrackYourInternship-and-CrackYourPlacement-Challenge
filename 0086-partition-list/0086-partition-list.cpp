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
    ListNode* partition(ListNode* head, int x) {
        if(!head||!head->next)
            return head;
        ListNode * smallHead  = new ListNode (-1);
        ListNode * smallTail = smallHead;
        ListNode * bigHead = new ListNode (-1);
        ListNode * bigTail = bigHead;
        while(head){
            if(head->val < x){
                smallTail->next = head;
                smallTail = smallTail->next;
            }
            else{
                bigTail->next = head;
                bigTail = bigTail->next;
            }
            head = head->next;
        }
        //figure out the pointers and nulls and connet small -> big
        bigTail->next = NULL;
        smallTail->next = NULL;
        if(bigHead==bigTail)
            return smallHead->next;
        if(smallHead == smallTail)
            return bigHead->next;
        smallTail->next = bigHead->next;
        bigHead->next = NULL;
        return smallHead->next;
    }
};