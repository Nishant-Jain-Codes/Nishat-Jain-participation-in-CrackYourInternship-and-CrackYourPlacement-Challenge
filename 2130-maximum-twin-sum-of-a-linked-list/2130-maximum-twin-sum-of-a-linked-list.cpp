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
    //time : O(N)
    //space : O(N)
    int pairSum(ListNode* head) {
        int size = 0;
        for(ListNode* temp = head; temp!=NULL;temp=temp->next)   
            size++;
        stack<int> s;
        ListNode* temp = head;
        for(int i = 0;i<size/2 && temp;i++){
            s.push(temp->val);
            temp = temp->next;
        }
        int ans = 0;
        while(temp){
            int curSum= s.top() + temp->val;
            s.pop();
            temp=temp->next;
            ans = max(curSum,ans);
        }
        return ans;
    }
};