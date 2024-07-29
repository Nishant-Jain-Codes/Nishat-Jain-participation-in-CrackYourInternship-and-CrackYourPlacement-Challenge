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
    //Space : O(N+M)
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
    //Time : O(N+M)
    //Space : O(1)
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
    ListNode * superOptimised(ListNode *headA, ListNode *headB){
        ListNode* a = headA;
        ListNode* b = headB;
        //when a pointer reaches the null , we are moving it to the start of the other list , this will make sure that the shorted list's pointer trave's the diff(l1-l2) distance and then both l1 and l2 's pointer will be aligned , i.e this just bypass the finding the length of l1 and l2 and shifting the bigger list's pointer to align the l1 , l2 
        while(a!=b){
            a = a==NULL ? headB : a->next;
            b = b==NULL ? headA : b->next;
        }
        return a ;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // return bruteForce(headA,headB);
        return superOptimised(headA,headB);
    }
};