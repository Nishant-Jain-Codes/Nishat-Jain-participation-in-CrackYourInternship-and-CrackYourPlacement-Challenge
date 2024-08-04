class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums ;
        for(int i = 0;i<nums.size();i++){
            int curSum = 0;
            for(int j = i;j<nums.size();j++){
                curSum+= nums[j];
                sums.push_back(curSum);
            }
        }
        // for(auto & x : sums)
        //     cout<<x<<" ";
        // cout<<endl;
        sort(sums.begin(),sums.end());
        long long int ans =0 ;
        int mod = 1e9 + 7;
        // for(auto & x : sums)
        //     cout<<x<<" ";
        // cout<<endl;
        // int ans = 0;
        for(int i = left-1;i<right;i++)
        {
            // cout<<sums[i]<<" ";
            ans = (ans+sums[i])%mod;
        }
        return ans;
    }
};