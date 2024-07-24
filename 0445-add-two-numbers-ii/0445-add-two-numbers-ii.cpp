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
    void putListInStack(ListNode* l , stack<int>& s){
        ListNode* temp = l;
        while(temp){
            s.push(temp->val);
            temp=temp->next;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> sfl1;
        stack<int>sfl2;
        stack<int> ans;
        putListInStack(l1,sfl1);
        putListInStack(l2,sfl2);
        int carry  = 0;
        ListNode * temp = new ListNode(0);
        ListNode * dummy = temp;
        // cout<<sfl1.size()<<" "<<sfl2.size()<<endl;
        while(!sfl1.empty() || !sfl2.empty() || carry){
            int v1 = 0;
            int v2 = 0;
            if(!sfl1.empty()){
                v1 = sfl1.top();
                sfl1.pop();
            }
            if(!sfl2.empty()){
                v2 = sfl2.top();
                sfl2.pop();
            }
            // cout<<v1<<" "<<sfl1.size()<<" "<<v2<<" "<<sfl2.size()<<" "<<carry<<" ";
            int valAdd = v1+v2+carry;
            carry = valAdd/10;
            valAdd%=10;
            // cout<<valAdd<<" "<<carry<<endl;
            ans.push(valAdd);
        }
        while(!ans.empty()){
            int valAdd = ans.top();
            ans.pop();
            ListNode* nodeAdd = new ListNode(valAdd);
            dummy->next = nodeAdd;
            dummy = dummy->next;
        }
        return temp->next;
    }
};