class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curPer;
        vector<vector<int>> allPer;
        unordered_set<int> takenIdx;
        doPermutations(nums,curPer,allPer,takenIdx);
        return allPer;
    }
private: 
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