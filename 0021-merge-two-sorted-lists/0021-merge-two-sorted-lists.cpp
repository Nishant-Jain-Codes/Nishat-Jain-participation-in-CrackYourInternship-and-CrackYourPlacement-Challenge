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
    ListNode* iterative(ListNode* list1, ListNode* list2){
        ListNode* dummyh = new ListNode(-1);
        ListNode * dummyt = dummyh;
        while(list1 && list2){
            if(list1->val<list2->val){
                dummyt->next = list1;
                list1=list1->next;
                dummyt=dummyt->next;
            }
            else
            {
                dummyt->next = list2;
                list2=list2->next;
                dummyt=dummyt->next;
            }
        }
        while(list1){
            dummyt->next = list1;
            list1=list1->next;
            dummyt=dummyt->next;
        }
        while(list2){
            dummyt->next = list2;
            list2=list2->next;
            dummyt=dummyt->next;
        }
        return dummyh->next;

    }
    ListNode* recursive(ListNode* list1, ListNode* list2) {
        if(!list1||!list2)
            return list1? list1: list2;
        if(list1->val>list2->val)
            swap(list1,list2);
        list1->next = recursive(list1->next,list2);
        return list1;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return recursive(list1,list2);
    }
};