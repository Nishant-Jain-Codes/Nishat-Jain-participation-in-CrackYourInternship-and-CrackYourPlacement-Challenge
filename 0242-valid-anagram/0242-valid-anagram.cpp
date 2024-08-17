class Solution {
public:
    //time : O(N)
    //space :O(1)
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        vector<int> sm(26,0);
        vector<int> tm(26,0);
        for(int i = 0 ; i<s.length();i++){
            sm[s[i]-'a']++;
            tm[t[i]-'a']++;
        }
        for(int i = 0 ; i<26;i++){
            if(sm[i]!=tm[i])
                return false;
        }
        return true;
    }
};