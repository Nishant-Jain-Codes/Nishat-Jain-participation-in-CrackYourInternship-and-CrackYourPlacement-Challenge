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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        for(ListNode* temp = head; temp!=NULL ; temp=temp->next)
            len++;
        // int sublen = len%k==0 ? len/k : 1+(len/k);
        
        vector<ListNode*> answer;
        for(int i = 0 ; i < k ; i++){
            ListNode dummy(-1);
            ListNode* tail = &dummy;
            int curLen = 0;
            int targetLen = len%(k-i)==0? len/(k-i) : len/(k-i) + 1;
            len-=targetLen;
            while(curLen<targetLen && head){
                tail->next = head;
                head=head->next;
                curLen++;
                tail=tail->next;
            }
            tail->next = NULL;
            answer.push_back(dummy.next);
        }
        return answer;
    }
};