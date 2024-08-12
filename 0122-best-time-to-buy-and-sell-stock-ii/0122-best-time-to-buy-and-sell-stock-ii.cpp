class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return dp_sol(prices);
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
private: 
    int dp_sol(vector<int> & prices){
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        for(int idx = prices.size()-1;idx>=0;idx--){
            for(int canBuy = 0 ; canBuy<=1 ; canBuy++){
                int ans = 0;
                if(canBuy){
                    int r1 = dp[idx+1][canBuy];
                    int r2 = dp[idx+1][!canBuy] - prices[idx];
                    ans = max(r1,r2);
                }
                else{
                    int r1 = dp[idx+1][canBuy];
                    int r2 = dp[idx+1][!canBuy] + prices[idx];
                    ans = max(r1,r2);
                }
                dp[idx][canBuy] = ans;
            }
        }
        return dp[0][1];
    }
};