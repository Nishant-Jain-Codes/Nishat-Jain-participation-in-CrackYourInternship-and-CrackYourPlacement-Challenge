class Solution {
public:
    //space : O(m*n)
    //time : O(m*n)
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rowHash(2,vector<int>(m));
        vector<vector<int>> colHash(2,vector<int>(n));
        for(int i = 0 ;i<m;i++){
            int zero = 0;
            int one = 0;
            for(int j = 0;j<n;j++){
                if(grid[i][j]==0)
                    zero++;
                else 
                    one++;
            }
            rowHash[0][i] = zero;
            rowHash[1][i] = one;
        }
        for(int i = 0;i<n;i++){
            int zero = 0;
            int one = 0;
            for(int j = 0 ; j<m;j++){
                if(grid[j][i] == 0)
                    zero++;
                else 
                    one++;
            }
            colHash[0][i] = zero;
            colHash[1][i] = one;
        }
        vector<vector<int>> answer(m,vector<int>(n,0));
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                answer[r][c] = rowHash[1][r] + colHash[1][c] - rowHash[0][r] - colHash[0][c];
            }
        }
        return answer;
    }
};