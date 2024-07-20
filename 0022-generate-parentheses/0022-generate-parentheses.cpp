class Solution {
public:
    // time compleixty : O(2^2n)
    // space compleixty : O(n) {auxilary stack space}
    void dfs(int open , int close , vector<string>& answer , string & curStr){
        if(close == 0){
            string curAns = curStr;
            answer.push_back(curAns);
            return ;
        }
        if(open >0){
            curStr.push_back('(');
            dfs(open-1,close,answer,curStr);
            curStr.pop_back();
        }
        if(open < close){
            curStr.push_back(')');
            dfs(open,close-1,answer,curStr);
            curStr.pop_back();
                
        }
            
    }
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string ans = "";
        dfs(n,n,answer,ans);
        return answer;
    }
};