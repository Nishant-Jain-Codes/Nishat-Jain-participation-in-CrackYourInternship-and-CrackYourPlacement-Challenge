class Solution {
public:
    int rob(vector<int>& nums) {
        return iterative(nums);
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return recursion(0,true,nums,dp);
    }
private:
    //time : O(2*N)
    //space : O(2*N)
    int iterative(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        int ans;
        for(int idx = n-1;idx>=0;idx--){
            for(int canRob = 0 ; canRob<=1 ; canRob++){
                if(canRob){
                    int rob = dp[idx+1][0] + nums[idx];
                    int notRob = dp[idx+1][1];
                    ans = max(rob,notRob);
                }
                else{
                    int notRob = dp[idx+1][1];
                    ans = notRob;
                }
                dp[idx][canRob] = ans;
            }
        }
        return dp[0][1];
    }
    //time : O(2*N)
    //space : O(2*N) + O(N) 
    int recursion(int idx , bool canRob , vector<int> & nums , vector<vector<int>> & dp){
        if(idx == nums.size())
            return 0;
        if(dp[idx][canRob]!=-1)
            return dp[idx][canRob];
        int ans ;
        if(canRob){
            int rob = recursion(idx+1,false,nums,dp) + nums[idx];
            int notRob = recursion(idx+1,true,nums,dp);
            ans = max(rob,notRob);
        }
        else
        {
            int notRob = recursion(idx+1,true,nums,dp);
            ans = notRob;
        }
        return dp[idx][canRob] = ans;
    }
};