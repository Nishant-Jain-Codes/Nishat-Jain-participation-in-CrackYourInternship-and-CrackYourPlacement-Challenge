class Solution {
public:
    // example input = { 1 , 3 , 4 , 5 ,7} , r= 2 , l = 6
    //lower_bound(2) = 3 ( 1st element not smaller than 2) 
    //upper_bound(6) = 7 (1st element greater than 7)
    //erase(l,r) => remove all elements from [l,r)
    void remove(set<int>&s , int l , int r){
        s.erase(s.lower_bound(l),s.upper_bound(r));
    }
    //time : O(nlogn + qlogn)
    //space : O(n)
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> s; 
        for(int i =0;i<n;i++)
            s.insert(i);
        vector<int> ans;
        for(auto &query : queries){
            int u= query[0],v=query[1];
            remove(s,u+1,v-1);
            ans.push_back(s.size()-1);
        }
        return ans;
    }
};