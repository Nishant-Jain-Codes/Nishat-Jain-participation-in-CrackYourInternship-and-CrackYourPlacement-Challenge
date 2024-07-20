class Solution {
public:
    // time : O(N*M) , M : size of largest string , N : total Strings
    // space : O(N)
    string countSort(string & str){
        int hash[26] = {0};
        for(auto &x : str)
            hash[x-'a']++;
        string output ="";
        for(int i=0;i<26;i++){
            for(int j = 0;j<hash[i];j++){
                output+= ('a'+i);
            }
        }
        return output;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(auto str : strs){
            string curStr = countSort(str);
            
            map[curStr].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto x : map){
            ans.push_back(x.second);
        }
        return ans;
    }
};