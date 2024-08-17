class Solution {
public:
    //time : O(N)
    //space : O(1)
    int findLengthOfLCIS(vector<int>& nums) {
        int i = 0;
        int ans = 1;
        while(i<nums.size())
        {
            int count = 1;
            while(i<nums.size()-1 && nums[i]<nums[i+1]){
                i++;
                count++;
            }
            ans = max(ans,count);
            i++;
        }
        return ans;
    }
};