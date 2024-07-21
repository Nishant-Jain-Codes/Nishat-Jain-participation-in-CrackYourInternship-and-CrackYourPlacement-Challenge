class Solution {
public:
    bool validLocation(vector<vector<char>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();
        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] != '1')
            return false;
        return true;
    }
    // time : O(N*M)
    // space : O(M*N) {auxiliary Stack Space}
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (!validLocation(grid, row, col))
            return;

        grid[row][col] = '2';

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // up,down,left,right
        for (int i = 0; i < 4; ++i) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            dfs(grid, newRow, newCol);
        }
    }
    // time : O(N*M)
    // space : O(min(N,M)) {auxiliary Stack Space}
    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        grid[row][col] = '2';
        while (!q.empty()) {
            auto [rowNow, colNow] = q.front();
            q.pop();
            // up,down,left,right
            for (int i = 0; i < 4; ++i) {
                int newRow = rowNow + directions[i][0];
                int newCol = colNow + directions[i][1];
                if (validLocation(grid, newRow, newCol)) {
                    grid[newRow][newCol] = '2';
                    q.push({newRow, newCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 0 || n == 0)
            return 0;

        int numberOfIslands = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++numberOfIslands;
                    // dfs(grid,i, j);
                    bfs(grid, i, j);
                }
            }
        }

        return numberOfIslands;
    }
};
