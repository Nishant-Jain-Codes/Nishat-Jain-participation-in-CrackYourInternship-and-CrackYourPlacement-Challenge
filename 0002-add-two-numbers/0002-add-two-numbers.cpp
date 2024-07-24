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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answerHead = NULL;
        ListNode* answerTail = NULL;
        int carry = 0;
        while(l1 || l2 ||carry){
            int v1 = l1? l1->val:0;
            int v2 = l2? l2->val:0;
            int valAdd = v1+v2+carry;
            carry = valAdd/10;
            valAdd%=10;
            ListNode* curNode = new ListNode(valAdd);
            if(!answerHead){
                answerHead = curNode;
                answerTail = answerHead;
            }
            else{
                answerTail->next = curNode;
                answerTail=answerTail->next;
            }
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        if(answerTail)
            answerTail->next = NULL;
        return answerHead;
    }
};