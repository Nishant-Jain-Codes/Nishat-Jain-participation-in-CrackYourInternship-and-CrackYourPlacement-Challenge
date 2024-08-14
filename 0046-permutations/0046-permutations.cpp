class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return method2(nums);
        // return method1(nums)
    }
private: 
    //time : O(n*n!)
    //space : O(n) 
    vector<vector<int>> method2(vector<int>&nums){
        vector<vector<int>> allPer;
        generatePermutations(0,nums,allPer);
        return allPer;
    }
    void generatePermutations(int idx , vector<int>&nums, vector<vector<int>>& allPers){
        if(idx == nums.size())
        {allPers.push_back(nums);
        return;}
        for(int i = idx ; i<nums.size();i++){
            swap(nums[idx],nums[i]);
            generatePermutations(idx+1,nums,allPers);
            swap(nums[i],nums[idx]);
        }
    }
private: 
    //time : O(n*n!)
    //space : O(n!)
    vector<vector<int>> method1(vector<int>&nums){
        vector<int> curPer;
        vector<vector<int>> allPer;
        unordered_set<int> takenIdx;
        doPermutations(nums,curPer,allPer,takenIdx);
        return allPer;
    }
    void doPermutations(vector<int>& nums , vector<int> & curPer , vector<vector<int>> & allPer , unordered_set<int> &takenIdx){
        if(curPer.size() == nums.size())
        {
            allPer.push_back(curPer);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(takenIdx.find(i)==takenIdx.end()){
                curPer.push_back(nums[i]);
                takenIdx.insert(i);
                doPermutations(nums,curPer,allPer,takenIdx);
                takenIdx.erase(i);
                curPer.pop_back();
            }
        }
    }
};