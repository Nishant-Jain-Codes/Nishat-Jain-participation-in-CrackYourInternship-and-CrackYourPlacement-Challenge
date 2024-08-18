class Solution {
public:
    //time : O(N)
    //space : O(1)
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        unordered_map<int,int> m;
        int size = 0;
        int ans = 0;
        while(r<s.length()){
            m[s[r]]++;
            if(m[s[r]]==1)
                size++;
            r++;
            if(size==(r-l)){
                ans = max(ans,size);
            }
            else{
                while(size!=(r-l)){
                    m[s[l]]--;
                    if(m[s[l]]==0)
                        size--;
                    l++;
                }
            }
        }
        return ans;
    }
};