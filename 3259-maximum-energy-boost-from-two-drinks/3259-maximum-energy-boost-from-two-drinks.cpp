class Solution {
public:
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
        vector<vector<long long>> dp(A.size(),vector<long long>(2,-1));
        return max(recursion(0,0,A,B,dp),recursion(0,1,A,B,dp));
    }
private: 
    long long recursion(int idx ,int curType ,vector<int>&A,vector<int>&B,vector<vector<long long>>&dp ){
        if(idx>=A.size())
            return 0;
        if(dp[idx][curType]!=-1)
            return dp[idx][curType];
        long long curVal = curType == 0 ? A[idx] : B[idx];
        //same
        long long same = curVal + recursion(idx+1,curType,A,B,dp);
        //different
        long long diff = recursion(idx+1,!curType,A,B,dp);
        long long ans = max(same,diff);
        return dp[idx][curType] = ans;
    }
};