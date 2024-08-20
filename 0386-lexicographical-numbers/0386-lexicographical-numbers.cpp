class Solution {
public:
    // time : O(nlog2n * log10n)
    // space : O(N)
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1;i<=n;i++){
            ans.push_back(i);
        }
        auto comp = [](int a , int b){
            return to_string(a)<to_string(b);
        };
        sort(ans.begin(),ans.end(),comp);
        return ans;
    }
};