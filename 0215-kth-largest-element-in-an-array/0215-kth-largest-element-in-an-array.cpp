class Solution {
public:
    // time : O(NLogK)
    // space : O(K)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minPq;
        for(auto &x : nums){
            minPq.push(x);
            if(minPq.size()>k)
                minPq.pop();
        }
        // int ans = 0;
        // while(!minPq.empty()){
        //     ans= minPq.top();
        //     minPq.pop();
        // }
        return minPq.top();
    }
};