class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        // priority_queue<int,vector<int>,greater<int>> pq;
        priority_queue<int> pq;
        while(pq.size()<k)
            pq.push(INT_MAX);
        vector<int> answer;
        for(auto &q:queries){
            pq.push(abs(q[0])+abs(q[1]));
            if(pq.size()>k)
                pq.pop();
            answer.push_back(pq.top()==INT_MAX?-1:pq.top());
        }
        return answer;
    }
};