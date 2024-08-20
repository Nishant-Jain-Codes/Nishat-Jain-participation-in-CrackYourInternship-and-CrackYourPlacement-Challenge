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
    ListNode* rotateRight(ListNode* head, int k) {
        int length = getLen(head);
        if(length<=1)
            return head;
        k%=length;
        if(!k )
            return head;
        ListNode* temp = head;
        for(int i = 0;i<length-k-1;i++)
            temp=temp->next;
        ListNode* secondHalf = temp->next;
        temp->next = NULL;
        temp=secondHalf;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next = head;
        return secondHalf;
    }
private : 
    int getLen(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp=temp->next;
            len++;
        }
        return len;
    }
};