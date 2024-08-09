class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int,int> freqMap;
        for(auto &x : nums)
            freqMap[x]++;
        vector<pair<int,int>> input(freqMap.begin(),freqMap.end());
        vector<int> curSet;
        vector<vector<int>> powerSet;
        generator(0,curSet,input,powerSet);
        return powerSet;
    }
private: 
    void generator(int idx , vector<int>&curSet , vector<pair<int,int>> &input , vector<vector<int>> & powerSet){
        if(idx == input.size())
            {
                powerSet.push_back(curSet);
                return;
            }
        for(int k = 0;k<=input[idx].second;k++){
            int num = input[idx].first;
            int freq = k;
            for(int i = 0 ; i<freq;i++){
                curSet.push_back(num);
            }
            generator(idx+1,curSet,input,powerSet);
            for(int i = 0 ; i<freq;i++){
                curSet.pop_back();
            }
        }   
    }
};