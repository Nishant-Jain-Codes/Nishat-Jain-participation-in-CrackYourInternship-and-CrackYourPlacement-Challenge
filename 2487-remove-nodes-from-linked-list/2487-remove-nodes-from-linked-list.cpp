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
    //time :O(N)
    //space :O(N)
    ListNode* removeNodes(ListNode* head) {
        vector<int> suffix;
        int curMax = 0;
        populateSuffix(head,suffix,curMax);
        reverse(suffix.begin(),suffix.end());
        int idx = 0;
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        while(head){
            if(head->val>=suffix[idx]){
                tail->next = head;
                tail=tail->next;
            }
            head = head->next; 
            idx++;
        }
        tail->next = NULL;
        return dummy.next;
        // for(auto &x : suffix)
        //     cout<<x<<" ";
        // return NULL;
    }
private : 
    void populateSuffix(ListNode* head, vector<int>& suffix,int & curMax){
        if(!head)
            return ;
        populateSuffix(head->next,suffix,curMax);
        suffix.push_back(curMax);
        curMax= max(curMax,head->val);
    }
};