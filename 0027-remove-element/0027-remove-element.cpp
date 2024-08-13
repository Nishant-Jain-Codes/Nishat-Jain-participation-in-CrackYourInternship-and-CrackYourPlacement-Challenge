class Solution {
public:
    //time : O(N)
    //space : O(1)
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(i<n){
            if(nums[i]!=val){
                nums[j] = nums[i];
                j++;
            }
            i++;
        }
        return j;
    }
};