class Solution {
public:
    int movesTox(vector<int>& nums , int x ){
        int ans = 0;
        for(auto a : nums){
            ans+= abs(a-x);
        }
        return ans;
    }
    int minMoves2(vector<int>& nums) {
        int sum = 0;
        // int ans = INT_MAX;
        // for(auto a : nums)
        //     sum+=a;
            // ans = min(ans,movesTox(nums,a));
        // return ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n%2 != 0)
            return movesTox(nums,nums[n/2]);
        else 
            return min(movesTox(nums,nums[n/2]),movesTox(nums,nums[n/2 -1]));
    }
};