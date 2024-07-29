/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //brute force (using hashing)
    ListNode *bruteForce(ListNode *headA , ListNode *headB){
        unordered_set<ListNode*> set;
        for(ListNode* temp = headA ; temp!=NULL ; temp = temp->next){
            set.insert(temp);
        }
        for(ListNode* temp = headB ; temp!=NULL ; temp = temp->next){
            if(set.find(temp)!=set.end())
                return temp;
            else 
                set.insert(temp);
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        return bruteForce(headA,headB);
    }
};