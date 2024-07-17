class Solution {
public:
    int bruteForce(vector<int>& prices){
        //time O(N^2)
        int maxProf = 0;
        for(int i = 0 ;i<prices.size();i++){
            for(int j = i+1; j<prices.size();j++){  
                maxProf = max(maxProf,prices[j]-prices[i]);
            }
        }
            return maxProf;
    }
    // time O(N)
    // space O(N)
    int optimised(vector<int>& prices){
        vector<int> curMax ;
        int curM = 0;
        int n = prices.size();
        for(int i = n-1;i>=0;i--){
            curMax.push_back(curM);
            curM=max(curM,prices[i]);
        }
        reverse(curMax.begin(),curMax.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,curMax[i]-prices[i]);
        }
        return ans;
    }
    // time O(N)
    //space O(1)
    int superOptimised(vector<int>& prices){
        int profit = 0;
        int minBuy = prices[0];
        for(int i=0;i<prices.size();i++){
            int sell = prices[i] - minBuy;
            profit = max(profit,sell);
            minBuy = min(minBuy,prices[i]);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return superOptimised(prices);
    }
};