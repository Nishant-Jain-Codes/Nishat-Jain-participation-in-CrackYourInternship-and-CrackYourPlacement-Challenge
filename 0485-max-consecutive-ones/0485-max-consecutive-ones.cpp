class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int i = 0;
      int ans =0;
      while(i<nums.size()){
        int cur=0;
        while(i<nums.size() && nums[i]==1){
            cur++;
            i++;
        }
        ans = max(ans,cur);
        i++;
      }  
      return ans;
    }
};