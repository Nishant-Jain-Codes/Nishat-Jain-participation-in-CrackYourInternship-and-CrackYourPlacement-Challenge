class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
      return min(recursion(0,cost,dp),recursion(1,cost,dp)) ; 
    }
private: 
    int recursion(int idx , vector<int>& cost , vector<int> &dp){
        if(idx >= cost.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        return dp[idx]=min(recursion(idx+1,cost,dp),recursion(idx+2,cost,dp)) + cost[idx];
    }
};