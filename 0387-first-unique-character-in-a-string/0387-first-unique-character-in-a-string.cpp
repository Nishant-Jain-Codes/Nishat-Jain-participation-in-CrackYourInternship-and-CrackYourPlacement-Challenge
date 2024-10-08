class Solution {
public:
    //time : O(N)
    //space : O(N)
    int firstUniqChar(string s) {
        unordered_map<int,int> m;
        for(auto &x : s)
            m[x]++;
        for(int i = 0;i<s.length();i++){
            if(m[s[i]]==1)
                return i;
        }
        return -1;
    }
};