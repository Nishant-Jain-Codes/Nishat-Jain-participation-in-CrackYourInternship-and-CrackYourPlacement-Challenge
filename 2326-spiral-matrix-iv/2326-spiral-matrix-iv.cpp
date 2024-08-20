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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* temp) {
        vector<vector<int>> mat(m,vector<int>(n,-1));
        int r = 0;
        int c = 0;
        int rS = 0;
        int rE = m-1;
        int cS = 0;
        int cE = n-1; 
        while(true){
            c=cS;
            r=rS;
            while(c<=cE && temp){
                mat[r][c] = temp->val;
                temp=temp->next;
                c++;
            }
            rS++;
            if(!temp)
                break;
            c=cE;r=rS;
            while(r<=rE && temp){
                mat[r][c] = temp->val;
                temp=temp->next;
                r++;
            }
            cE--;
            if(!temp)
                break;
            c=cE;r=rE;
            while(c>=cS && temp){
                mat[r][c] = temp->val;
                temp = temp->next;
                c--;
            }
            rE--;
            if(!temp)
                break;
            c=cS;r=rE;
            while(r>=rS && temp){
                mat[r][c] = temp->val;
                temp = temp->next;
                r--;
            }
            cS++;
        }
        return mat;
    }
};