class Solution {
public:
    //time : O(N)
    //space : O(N)
    string frequencySort(string s) {
        unordered_map<int,int> m;
        for(auto & c : s)
            m[c]++;
        vector<pair<int,int>> v(m.begin(),m.end());
        auto comp = [](pair<int,int>&p1, pair<int,int>&p2){
            return p1.second>p2.second;
        };
        sort(v.begin(),v.end(),comp);
        string ans = "";
        for(int i = 0;i<v.size();i++){
            for(int j = 0;j<v[i].second;j++)
                ans.push_back(v[i].first);
        }
        return ans;
    }
};