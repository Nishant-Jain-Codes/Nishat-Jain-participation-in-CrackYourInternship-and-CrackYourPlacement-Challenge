class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                stk.push(s[i]);
            else{
                char curBracket = s[i];
                if(stk.empty())
                    return false;
                char curStakTop = stk.top();
                stk.pop();
                if(curBracket == ')' && curStakTop!='(')
                    return false;
                if(curBracket == '}' && curStakTop!='{')
                    return false;
                if(curBracket == ']' && curStakTop!='[')
                    return false;
            }
        }
        return stk.empty();
    }
};