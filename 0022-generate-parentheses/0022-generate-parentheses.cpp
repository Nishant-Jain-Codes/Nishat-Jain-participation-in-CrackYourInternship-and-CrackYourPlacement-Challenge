class Solution {
public:
    // time compleixty : O()
    // space compleixty : O()
    void helper(int open , int close , vector<string>& answer , string & curStr){
        if(close == 0){
            string curAns = curStr;
            answer.push_back(curAns);
            return ;
        }
        if(open == close){
            curStr.push_back('(');
            helper(open-1,close,answer,curStr);
            curStr.pop_back();
        }
        else{
            if(open>0){
                curStr.push_back('(');
                helper(open-1,close,answer,curStr);
                curStr.pop_back();
            }
            curStr.push_back(')');
            helper(open,close-1,answer,curStr);
            curStr.pop_back();
                
        }
            
    }
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string ans = "";
        helper(n,n,answer,ans);
        return answer;
    }
};