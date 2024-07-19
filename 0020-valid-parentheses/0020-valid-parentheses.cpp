

class Solution {
public:

    // time : O(N)
    // space : O(N)
    bool isValid(string s){
        stack<char> stk;
        unordered_map<char,char> bracketPair = {{')','('},{'}','{'},{']','['}};
        for( auto ch : s){
            if(bracketPair.find(ch)!=bracketPair.end()){
                if(stk.empty() || stk.top() != bracketPair[ch])
                    return false;
                else 
                    stk.pop();
            }
            else
                stk.push(ch);
        }
        return stk.empty();
    }

    // time : O(N)
    // space : O(N)
    bool isValid_poorlyWrittenCode(string s) {
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