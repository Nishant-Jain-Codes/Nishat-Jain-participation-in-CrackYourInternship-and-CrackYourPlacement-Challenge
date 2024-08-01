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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        pair<ListNode* , ListNode* > lists= splitList(head);
        ListNode* left =  lists.first;
        ListNode* right = lists.second; 
        left = sortList(left);
        right = sortList(right);
        head = mergeSortedLists(left,right);
        return head;
    }
private: 
    pair<ListNode* , ListNode* > splitList(ListNode* head){
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * mid = slow;
        ListNode* first = head;
        ListNode* second = mid->next;
        mid->next = NULL;
        return {first,second};
    }   
    ListNode* mergeSortedLists(ListNode* first, ListNode* second){
        ListNode * dummyH = new ListNode(-1);
        ListNode * dummyT = dummyH;
        while(first&&second){
            if(first->val < second->val){
                dummyT->next = first;
                first = first->next;
            }
            else{
                dummyT->next = second;
                second = second->next;
            }
            dummyT = dummyT->next;
        }
        if(first)
            dummyT->next = first;
        if(second)
            dummyT->next = second;
        return dummyH->next;
    }
};