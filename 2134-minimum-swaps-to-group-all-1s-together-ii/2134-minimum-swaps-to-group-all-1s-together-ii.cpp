class Solution {
public:
    int close(vector<int>& nums , int k)
    {
        int si = 0;
        int ei = nums.size()-1;
        while(si<=ei && nums[si]!=k)
            si++;
        while(ei>=si && nums[ei]!=k)
            ei--;
        int count = 0;
        int l =  si;
        int r = ei;
        while(l<=r){
            if(nums[l] == k) 
                count++;
            l++;
        }
        int minDiff = ei-si + 1 - count;
        cout<<si<<" "<<ei<<" for -> "<<k<<" "<<minDiff<<endl;
        return minDiff;
    }
    int minSwaps(vector<int>& nums) {
        return min(close(nums,0),close(nums,1));
    }
};