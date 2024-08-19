class Solution {
public:
    int totalNQueens(int n) {
        vector<int> cols(n, -1);  // Store the column positions of queens
        return dfs(0, cols, n);
    }
private:
    int dfs(int row, vector<int>& cols, int n) {
        if (row == n) return 1;
        int ways = 0;
        for (int c = 0; c < n; ++c) {
            if (isValid(row, c, cols)) {
                cols[row] = c;
                ways += dfs(row + 1, cols, n);
                cols[row] = -1;  // Backtrack
            }
        }
        return ways;
    }
    
    bool isValid(int r, int c, vector<int>& cols) {
        for (int i = 0; i < r; ++i) {
            if (cols[i] == c || abs(cols[i] - c) == abs(i - r))
                return false;
        }
        return true;
    }
};
