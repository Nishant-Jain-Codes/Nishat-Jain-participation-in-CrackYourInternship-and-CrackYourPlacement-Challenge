class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find first decreasing idx
        int right = nums.size()-2;
        while(right>=0)
        {
            if(nums[right+1]>nums[right])
                break;
            right--;
        }
        cout<<right;
        if(right == -1)
        {
            sort(nums.begin(),nums.end());
        }
        else{
            int eleIdx = -1;
            for(int i = right+1; i<nums.size();i++){
                if(nums[i]>nums[right] && (eleIdx == -1 || nums[eleIdx]>nums[i]))
                    eleIdx = i;
            }
            swap(nums[eleIdx],nums[right]);
            sort(nums.begin()+right+1,nums.end());
        }
    }
};