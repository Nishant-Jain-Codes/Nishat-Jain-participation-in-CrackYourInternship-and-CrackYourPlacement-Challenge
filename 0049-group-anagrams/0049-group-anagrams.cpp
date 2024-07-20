class Solution {
public:
    // time : O(N)
    // space : O(N)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(auto str : strs){
            string curStr = str;
            sort(curStr.begin(),curStr.end());
            map[curStr].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto x : map){
            ans.push_back(x.second);
        }
        return ans;
    }
};