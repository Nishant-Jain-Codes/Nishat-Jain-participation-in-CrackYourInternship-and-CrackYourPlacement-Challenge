class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int ans = -1;
        while(l<r){
            int mid = (l+r)>>1;
            if(nums[mid]>target)
                r=mid-1;
            else if(nums[mid]<target)
                l = mid+1;
            else 
                return mid;
        }
        if(nums[l]<target)
            return l+1;
        else 
            return l;
    }
};