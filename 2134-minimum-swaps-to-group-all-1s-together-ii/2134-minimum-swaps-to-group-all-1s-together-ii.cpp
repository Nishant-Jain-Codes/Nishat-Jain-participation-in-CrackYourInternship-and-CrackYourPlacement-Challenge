class Solution {
public:
    int sw(vector<int>& nums,int k ){
        int count = 0;
        for(auto &x : nums){
            if(x==k)
                count++;
        }
        int kCount = 0;
        int notKCount = 0;
        for(int i =0;i<count;i++){
            if(nums[i]==k)
                kCount++;
            else
                notKCount++;
        }
        int ans = notKCount;
        for(int i = count;i<nums.size();i++){
            if(nums[i]==k)
                kCount++;
            else
                notKCount++;
            if(nums[i-count] == k)
                kCount--;
            else
                notKCount--;
            ans = min(ans,notKCount);
        }
        return ans;
    }
    int minSwaps(vector<int>& nums) {
        return min(sw(nums,1),sw(nums,0));
    }
};