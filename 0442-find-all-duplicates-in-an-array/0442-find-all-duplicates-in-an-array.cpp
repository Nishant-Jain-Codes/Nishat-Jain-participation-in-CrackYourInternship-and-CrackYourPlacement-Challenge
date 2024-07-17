class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans ;
        for(int i = 0;i<nums.size();i++){
            int curNum = abs(nums[i])-1;
            if(nums[curNum]<0){
                ans.push_back(curNum+1);
            }
            else{
                nums[curNum]*=-1;
            }
        }
        return ans;
    }
};