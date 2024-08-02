class Solution {
public:
    int sw(vector<int>& nums,int k ){
        int totalK = 0;
        for(auto & x : nums)
            if(x == k) 
                totalK++;
        int nonKcount = 0;
        for(int i =0;i<totalK;i++)
            if(nums[i]!=k)
                nonKcount++;
        int minSwaps  = nonKcount;
        for(int i = totalK ; i<nums.size();i++){
            if(nums[i]!=k) nonKcount++;
            if(nums[i-totalK]!=k) nonKcount--;
            minSwaps = min(minSwaps,nonKcount);
        }
        return minSwaps;
    }
    //time : O(N)
    //space : O(1)
    int minSwaps(vector<int>& nums) {
        return min(sw(nums,1),sw(nums,0));
    }
};