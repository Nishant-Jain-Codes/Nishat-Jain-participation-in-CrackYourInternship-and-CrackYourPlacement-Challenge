class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int right = nums.size()-2;
        while(right>=0 && nums[right+1]<= nums[right])
            right--;
        if(right>=0){
            int eleIdx = nums.size()-1;
            while(nums[eleIdx]<=nums[right])
                eleIdx--;
            swap(nums[right],nums[eleIdx]);
        }
        reverse(nums.begin()+right+1,nums.end());
    }
};