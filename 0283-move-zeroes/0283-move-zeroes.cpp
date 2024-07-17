class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 2 pointer approch 
        int nextNonZeroLoc = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                continue;
            }
            else{
                nums[nextNonZeroLoc]=nums[i];
                nextNonZeroLoc++;
            }
        }
        while(nextNonZeroLoc<nums.size()){
            nums[nextNonZeroLoc]=0;
            nextNonZeroLoc++;
        }
    }
};