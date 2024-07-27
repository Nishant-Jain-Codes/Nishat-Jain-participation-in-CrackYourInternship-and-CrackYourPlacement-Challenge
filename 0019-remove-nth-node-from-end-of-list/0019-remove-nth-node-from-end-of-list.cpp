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
    ListNode* helper(ListNode* head , int n , int &curN){
        if(!head)
            {
                curN = 0;
                return head;
            }
        head->next = helper(head->next,n,curN);
        if(curN == n){
            if(head->next!=NULL)
            {
                ListNode* temp = head->next;
                head->next=head->next->next;
                temp->next = NULL;
                delete temp;
                
            }
        }
        curN++;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==0)
            return head;
        int val = 0;
        ListNode * answer = helper(head,n,val);
        if(val == n)
            return answer->next;
        else
            return answer;
    }
};