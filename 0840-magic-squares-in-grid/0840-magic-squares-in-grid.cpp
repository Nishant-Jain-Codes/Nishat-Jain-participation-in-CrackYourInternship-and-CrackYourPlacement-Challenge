class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count=0;
        for(int r = 0;r<= rows-3;r++){
            for(int c = 0;c<=cols-3;c++){
                vector<int> values;
                unordered_set<int> s;
                bool flag = false;
                //r1 , r2 , r3 
                for(int k = 0;k<3;k++){
                    int sum = 0;
                    for(int i = c;i<c+3;i++){
                        s.insert(grid[r+k][i]);
                        if(grid[r+k][i]>10)
                            flag = true;
                        sum+=grid[r+k][i];
                    }
                    values.push_back(sum);
                }
                if(s.size()!=9 || flag)
                    continue;
                //r1 , r2 , r3
                for(int k = 0;k<3;k++){
                    int sum = 0;
                    for(int i = r;i<r+3;i++){
                        sum+=grid[i][c+k];
                    }
                    values.push_back(sum);
                }
                //d primary , d secondary
                int dp = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
                int ds = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];
                values.push_back(dp);
                values.push_back(ds);
                int i = 0;
                while(i<values.size()-1 && values[i] == values[i+1])
                    i++;
                if(i==values.size()-1)
                    count++;
            }
        } 
        return count;
    }
};