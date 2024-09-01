class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n != original.size())
            return {};
        vector<vector<int>> answer(m,vector<int>(n));
        for(int r = 0 ; r<m;r++){
            for(int c=0;c<n;c++){
                answer[r][c] = original[(n*r + c)];
            }
        }
        return answer;
    }
};