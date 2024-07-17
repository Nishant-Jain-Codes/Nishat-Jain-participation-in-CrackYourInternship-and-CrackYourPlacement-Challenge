class Solution {
public:
    //O(N) time 
    //O(N) space
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp ; //number , index
        // for(int i =0;i<nums.size();i++){
        //     mp[nums[i]] = i ;
        // }
        // vector<int> ans;
        for(int i =0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end() && mp[target-nums[i]]!=i){
                return {i,mp[target-nums[i]]};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};