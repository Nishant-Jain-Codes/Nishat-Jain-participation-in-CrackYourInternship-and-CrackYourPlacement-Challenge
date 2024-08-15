class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int i = 2;i<n;i++){
            cost[i]+= min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-1],cost[n-2]);
        //method 2 time : O(2N)
        // return min(dpHelper(cost,0),dpHelper(cost,1));

    }
private:
    int dpHelper(vector<int>&cost,int endI){
        int n = cost.size();
        // vector<int> dp(n+2,0);
        int one = 0;
        int two = 0;
        int costAns ;
        for(int idx = n-1;idx>=endI;idx--){
            costAns = min(one,two) + cost[idx];
            one = two;
            two = costAns;
        }
        return costAns;

    }
};