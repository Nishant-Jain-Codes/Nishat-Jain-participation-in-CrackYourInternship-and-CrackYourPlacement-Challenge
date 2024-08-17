class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, { 'M', 1000 }};
            int ans = 0;
            for(int i = s.length()-1;i>=0;i--){
                int curVal = m[s[i]];
                if(curVal>=ans || (i!=s.length()-1 && s[i] == s[i+1]))
                    ans+=curVal;
                else 
                    ans-=curVal;
            }
            return ans;
        
    }
};