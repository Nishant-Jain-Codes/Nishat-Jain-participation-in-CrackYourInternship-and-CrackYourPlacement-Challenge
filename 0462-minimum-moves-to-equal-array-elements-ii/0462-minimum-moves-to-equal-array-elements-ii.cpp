class Solution {
public:
    // (maths property) median minimses the sum of absolute differences 
    //time : O(N)
    //space : O(1)
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int median = nums[n/2];
        int ans = 0;
        //in case of even size also , either median value will give the minimsed difference
        for(auto a : nums){
            ans+= abs(a-median);
        }
        return ans;
    }
};