class Solution {
public:
    // time : O(N^3)
    // space : O(1)
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        if(nums.size()<=3)
            return {};
        vector<vector<int>> answer;
        long long int target = t;
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size()-3;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
                target=target-nums[i];
            for(int j = i+1;j<nums.size()-2;j++){
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                int si = j+1;
                int ei = nums.size()-1;
                target=target-nums[j];
                while(si<ei){
                    long long int sum =+nums[si]+nums[ei];
                    if(sum==target){
                        answer.push_back({nums[i],nums[j],nums[si],nums[ei]});
                        if(nums[si]==nums[ei])
                            break;
                        else{
                            while(nums[si]==nums[si+1])
                                si++;
                            while(nums[ei]==nums[ei-1])
                                ei--;
                            si++;
                            ei--;
                        }
                    }
                    else if (sum<target){
                        si++;
                    }
                    else{
                        ei--;
                    }
                }
                target=target+nums[j];
            }
            target=target+nums[i];
        }
        return answer;
    }
};