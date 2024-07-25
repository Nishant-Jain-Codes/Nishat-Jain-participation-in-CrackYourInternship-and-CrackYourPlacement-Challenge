class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        // int count = 0;
        vector<vector<int>> answer;
        while(i<nums.size()-2){
            int li=i+1;
            int ri=nums.size()-1;
            while(li<ri){
                int sum = nums[i]+nums[li]+nums[ri];
                if(sum==0){
                    // count++;
                    answer.push_back({nums[i],nums[li],nums[ri]});
                    if(nums[li]==nums[ri]){
                        break;
                    }
                    else{
                        while(nums[li]==nums[li+1])
                            li++;
                        while(nums[ri]==nums[ri-1])
                            ri--;
                        li++;
                        ri--;
                    }
                }
                else if(sum>0)
                    ri--;
                else
                    li++;
            }
            while(i<nums.size()-2 && nums[i]==nums[i+1])
                i++;
            i++;
        }
        return answer;
    }
};