class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0;
        for(int i = 0;i<s.length();i++){
            int one = 0;
            int zero = 0;
            for(int j = i;j<s.length();j++){
                if(s[j]=='1')
                    one++;
                else 
                    zero++;
                if(one<=k || zero<=k)
                    ans++;
            }
        }
            return ans;
    }
};