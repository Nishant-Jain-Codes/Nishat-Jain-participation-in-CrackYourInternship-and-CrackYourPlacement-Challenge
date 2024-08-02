class Compare
{
public:
    bool operator() (pair<int,int> &p1, pair<int,int>&p2)
    {
        return p1.second>p2.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto &x:nums)
            map[x]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>,Compare> minPq;
        for(auto &[no,freq] : map){
            minPq.push({no,freq});
            if(minPq.size()>k)
                minPq.pop();
        }
        vector<int> ans(k);
        int i = 0;
        while(!minPq.empty()){
            ans[i] = minPq.top().first;
            i++;
            minPq.pop();
        }
        return ans;
    }
};