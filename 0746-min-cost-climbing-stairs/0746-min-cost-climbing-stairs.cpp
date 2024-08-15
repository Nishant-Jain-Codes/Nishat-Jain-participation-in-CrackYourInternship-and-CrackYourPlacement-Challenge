class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(dpHelper(cost,0),dpHelper(cost,1));

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