class Solution {
public:
    //time O(N^2)
    //space O(N)
    bool recursion(vector<int>& nums, int curIdx , vector<int>& dp){
        if(curIdx >= nums.size()-1)
            return true;
        if(dp[curIdx]!=-1)
            return dp[curIdx];
        int curStrength = nums[curIdx];
        int canReach = false;
        if(curStrength+curIdx >= nums.size()-1)
            return dp[curIdx]=true;
        for(int i= curIdx+1 ; i<= curIdx+curStrength ;i++){
                if(recursion(nums,i,dp))
                    return dp[curIdx]=true;
        }
        return dp[curIdx]=false;
    }

    bool canJump(vector<int>& nums) {
        // vector<int> dp(nums.size(),-1);
        // return helper(nums,0,dp);
        //Optimised solution GREEDY 
        // Time : O(N)
        // Space : O(1)
        int curMaxDest = 0;
        for(int i = 0;i<nums.size();i++){
            if(curMaxDest<i)
                return false;
            curMaxDest = max(curMaxDest , nums[i]+i);       if(curMaxDest>=nums.size())
                return true;
        }
        return true;
    }
};