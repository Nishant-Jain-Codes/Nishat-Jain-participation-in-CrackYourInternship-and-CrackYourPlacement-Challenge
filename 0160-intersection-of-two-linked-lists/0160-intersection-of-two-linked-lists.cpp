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
    //Time : O(N+M)
    //Space : o(N+M)
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
    int length(ListNode*head){
        int l = 0;
        ListNode* temp = head;
        while(temp){
            temp=temp->next;
            l++;
        }
        return l;
    }
    ListNode *optimised(ListNode *headA, ListNode *headB){
        int l1 = length(headA);
        int l2 = length(headB);
        ListNode* big = headA;
        ListNode* sml = headB;
        if(l1<l2)
            {
                swap(big,sml);
                swap(l1,l2);
            }
        int diff = l1-l2;
        while(diff){
            big=big->next;
            diff--;
        }
        while(big!=sml){
            big=big->next;
            sml=sml->next;
        }
        return big==NULL? NULL:big;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // return bruteForce(headA,headB);
        return optimised(headA,headB);
    }
};