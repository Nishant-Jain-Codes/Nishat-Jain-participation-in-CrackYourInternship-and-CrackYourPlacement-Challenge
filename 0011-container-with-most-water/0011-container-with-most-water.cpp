class Solution {
public:
    //greedy
    //time O(N)
    //space O(1)
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int curMax = 0;
        while(l<r){
            int curDist = r-l;
            int curHeight = min(height[l],height[r]);
            int curVol = curHeight*curDist;
            curMax = max(curMax,curVol);
            if(height[l]<=height[r])
                l++;
            else
                r--;

        }
        return curMax;
    }
};