class Solution {
public:
    //time : O(N)
    //space : O(N)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;//<prefuxSum,freq> 
        map[0] = 1;
        int curSum = 0;
        int ans = 0;
        for(int i =0;i<nums.size();i++){
            curSum+=nums[i];
            int remove = curSum-k;
            ans+=map[remove];
            map[curSum]++;
        }
        return ans;
    }
};