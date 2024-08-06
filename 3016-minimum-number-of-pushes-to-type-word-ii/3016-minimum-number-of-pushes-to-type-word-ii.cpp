class Solution {
public:
// time : O(N)
// space : O(N)
    int minimumPushes(string word) {
        unordered_map<char,int> m;
        for(auto&x : word)
            m[x]++;
        vector<pair<char,int>> vec(m.begin(),m.end());
        // for(auto &x : m)
        // {
        //     vec.push_back({x.first,x.second});
        // }
        sort(vec.begin(),vec.end(),[&](pair<char,int>&p1,pair<char,int>& p2){
            return p1.second>p2.second; //sort in desceding order
        });
        int count = 0;
        int multiplier = 1;
        int left = 8;
        for(auto &[key,freq]:vec){
            if(left==0)
            {
                left = 8;
                multiplier++;
            }
            count+= (freq*multiplier);
            left--;
        }
        return count;
    }
};