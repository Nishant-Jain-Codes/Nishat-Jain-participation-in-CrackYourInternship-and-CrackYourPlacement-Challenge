class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,pair<int,int>> map;//<prefuxSum,freq> 
        map[0] = {1,-1};
        int curSum = 0;
        int ans = 0;
        for(int i =0;i<=nums.size();i++){
            if(i<nums.size())
            curSum+=nums[i];
            else if(k==0)
                continue;
            int target = curSum-k;
            if(map.find(target)!=map.end()){
                ans+=map[target].first;
            }
            map[target].first++;
            map[target].second = i;
        }
        return ans;
    }
};