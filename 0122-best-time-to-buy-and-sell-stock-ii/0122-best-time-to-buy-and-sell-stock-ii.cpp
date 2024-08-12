class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return recursion(prices,0,true,dp);
    }
private : 
    int recursion(vector<int>& prices , int idx , bool canBuy,vector<vector<int>> &dp){
        if(idx == prices.size())
        {
            return 0;
        }
        if(dp[idx][canBuy]!=-1)
            return dp[idx][canBuy];
        int ans ;
        if(canBuy){
            int r1 = recursion(prices,idx+1,canBuy,dp);
            int r2 = recursion(prices,idx+1,!canBuy,dp) - prices[idx];
            ans  = max(r1,r2);
        }
        else{
            int r1 = recursion(prices,idx+1,canBuy,dp);
            int r2 = recursion(prices,idx+1,!canBuy,dp)+prices[idx];
            ans =  max(r1,r2);
        }
        return dp[idx][canBuy] = ans;
    }
};