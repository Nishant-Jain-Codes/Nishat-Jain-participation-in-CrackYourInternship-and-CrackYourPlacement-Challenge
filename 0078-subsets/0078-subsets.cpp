class Solution {
public:
    void helper(vector<int>& nums , vector<vector<int>>&powerSet,int curIdx,vector<int>& curSet){
        if(curIdx == nums.size()){
            vector<int> addSet(curSet);
            powerSet.push_back(addSet);
            return ;
        }
        //not take 
        helper(nums,powerSet,curIdx+1,curSet);
        //take
        curSet.push_back(nums[curIdx]);
        helper(nums,powerSet,curIdx+1,curSet);
        curSet.pop_back();
    }
    // time : O(2^N)
    // time : O(N*2^N)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curSet;
        vector<vector<int>> powerSet;
        helper(nums,powerSet,0,curSet);
        // vector<vector<int>> answer(powerSet);
        return powerSet;
    }
};