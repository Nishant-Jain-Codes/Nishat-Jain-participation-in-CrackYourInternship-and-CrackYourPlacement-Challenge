class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2,0);
        for(int idx = n-1;idx>=0;idx--){
            dp[idx] = min(dp[idx+1],dp[idx+2]) + cost[idx];
        }
        return min(dp[0],dp[1]);

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