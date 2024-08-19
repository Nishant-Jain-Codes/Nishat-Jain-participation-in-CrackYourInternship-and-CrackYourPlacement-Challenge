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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)
            return head;
        //if even
        // dt -> next = nextN;
        // cur->next = nextN->next;
        // nextN -> net = cur;
        ListNode* curNode = head;
        ListNode* nextNode = head->next; 
        ListNode dummy(-1);
        ListNode* dummyT = &dummy;
        while(nextNode){
            dummyT->next = nextNode;
            curNode->next = nextNode->next;
            nextNode->next = curNode;
            dummyT=curNode;
            curNode=curNode->next;
            
            nextNode=curNode?curNode->next:NULL;
        }   
        return dummy.next;
    }
};