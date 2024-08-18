class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> allWays;
        dfs(0,s,allWays);
        return allWays;
    }
private : 
    void dfs(int idx , string &s , vector<string>& allWays){
        if(idx == s.length())
            {
                allWays.push_back(s);
                return;
            }
        //not take
        dfs(idx+1,s,allWays);
        //take
        if(isalpha(s[idx])){
            char prev = s[idx];
            s[idx] = islower(s[idx]) ? toupper(s[idx]) : tolower(s[idx]);
            dfs(idx+1,s,allWays);
            s[idx] = prev;
        }
    }
};