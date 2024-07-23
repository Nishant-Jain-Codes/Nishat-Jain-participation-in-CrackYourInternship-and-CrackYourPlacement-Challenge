class Solution {
public:
    bool helper(vector<int>& nums, int curIdx , vector<int>& dp){
        if(curIdx >= nums.size()-1)
            return true;
        if(dp[curIdx]!=-1)
            return dp[curIdx];
        int curStrength = nums[curIdx];
        int canReach = false;
        if(curStrength+curIdx >= nums.size()-1)
            return dp[curIdx]=true;
        for(int i= curIdx ; i<= curIdx+curStrength ;i++){
            if(i!=curIdx)
                if(helper(nums,i,dp))
                    return dp[curIdx]=true;
        }
        return dp[curIdx]=false;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums,0,dp);
    }
};