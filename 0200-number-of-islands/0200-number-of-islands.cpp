class Solution {
public:
    // time : O(N*M)
    // space : O(min(N,M)) {auxiliary Stack Space}
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();
        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == '0' || visited[row][col])
            return;
        
        visited[row][col] = true;
        
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        //up,down,left,right
        for (int i = 0; i < 4; ++i) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            dfs(grid, visited, newRow, newCol);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (m == 0 || n == 0)
            return 0;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int numberOfIslands = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++numberOfIslands;
                    dfs(grid, visited, i, j);
                }
            }
        }
        
        return numberOfIslands;
    }
};
