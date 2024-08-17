class Solution {
public:
    //time : O(n^2)
    vector<int> resultsArray(vector<int>& nums, int k) {
        //brute force
        int n = nums.size();
        vector<int> ans;
        for(int i = 0;i<=n-k;i++){
            bool isSorted = true;
            for(int j = 1 ; j<k;j++){
                if(nums[i+j] != nums[i+j-1] + 1)
                    {
                        isSorted = false;
                        break;
                    }
            }
            if(isSorted)
                ans.push_back(nums[i+k-1]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};