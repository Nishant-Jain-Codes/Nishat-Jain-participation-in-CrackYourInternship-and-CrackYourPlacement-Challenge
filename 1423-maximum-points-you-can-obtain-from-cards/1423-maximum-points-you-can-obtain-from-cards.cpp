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
    
    //time : O(2^N)
    //space : O(N) {auxilary stack space}
    int recursive_solution(vector<int>& cardPoints, int k) {
        return helper(cardPoints,0,cardPoints.size()-1,k);
    }
    //time : O(N)
    // space : O(1)
    int sliding_window(vector<int>& cardPoints, int k) {
        int total_sum = 0;
        for(auto x : cardPoints)
            total_sum+=x;
        int sw = 0,ew=0;
        int windowSum = 0;
        int answer = INT_MIN;
        if(k == cardPoints.size())
            return total_sum;
        while(ew<cardPoints.size()){
            windowSum+=cardPoints[ew];
            if(ew-sw+1 == cardPoints.size()-k){
              answer = max(answer,total_sum-windowSum);
              
            //   ew++;
            //   windowSum+=cardPoints[ew];
              windowSum-=cardPoints[sw];
              sw++;
              
            }
            // else{
                ew++;
            // }
        }

        return answer;
    }
    int maxScore(vector<int>& cardPoints, int k) {
        return sliding_window(cardPoints,k);
    }
};