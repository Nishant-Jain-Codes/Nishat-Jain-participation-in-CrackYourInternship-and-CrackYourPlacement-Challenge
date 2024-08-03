class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> map;
        for(auto &x : arr)
            map[x]++;
        for(auto &x : target){
            if(map.find(x)==map.end())
                return false;
            map[x]--;
        }
        for(auto [no,freq]  : map){
            if(freq!=0)
                return false;
        }
        return true;
    }
};