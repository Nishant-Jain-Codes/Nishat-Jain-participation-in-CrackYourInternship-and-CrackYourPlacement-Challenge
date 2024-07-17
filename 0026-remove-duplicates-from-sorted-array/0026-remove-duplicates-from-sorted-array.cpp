class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1 )
            return nums.size();
            
        int i =0;
        int j = 0;
        while(j<nums.size()-1){
            while(j<nums.size()-1 && nums[j]==nums[j+1]){
                j++;
            }
            nums[i]=nums[j];
            j++;
            i++;
        }
        if(j== nums.size()-1 && nums[j]!=nums[j-1]){
            nums[i] = nums[j];
            i++;
        }
        return i;
    }
};