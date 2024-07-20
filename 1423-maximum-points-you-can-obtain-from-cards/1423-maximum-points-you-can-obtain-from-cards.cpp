class Solution {
public:
    int helper(vector<int>& points , int si , int ei , int k ){
        if(k==0)
            return 0;
        if(si>ei)
            return 0;
        if(si==ei)
            return points[si];
        return max(points[si]+helper(points,si+1,ei,k-1),points[ei]+helper(points,si,ei-1,k-1));
    }
    int maxScore(vector<int>& cardPoints, int k) {
        return helper(cardPoints,0,cardPoints.size()-1,k);
    }
};