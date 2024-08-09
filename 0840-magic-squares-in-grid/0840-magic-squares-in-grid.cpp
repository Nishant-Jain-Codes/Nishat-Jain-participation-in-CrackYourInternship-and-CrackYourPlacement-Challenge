class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        // Helper function to check if a 3x3 grid is a magic square
        auto isMagicSquare = [&](int r, int c) {
            unordered_set<int> s;
            int rowSum = 0, colSum = 0, diagSum1 = 0, diagSum2 = 0;
            for (int i = 0; i < 3; ++i) {
                rowSum = colSum = 0;
                for (int j = 0; j < 3; ++j) {
                    int num = grid[r + i][c + j];
                    // Check if number is within range and unique
                    if (num < 1 || num > 9 || !s.insert(num).second) {
                        return false;
                    }
                    rowSum += num;
                    colSum += grid[r + j][c + i];
                }
                // Check if all rows and columns have the same sum
                if (i == 0) {
                    diagSum1 = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
                    diagSum2 = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];
                    if (rowSum != colSum || rowSum != diagSum1 || rowSum != diagSum2) {
                        return false;
                    }
                } else if (rowSum != colSum || rowSum != diagSum1) {
                    return false;
                }
            }
            return true;
        };

        // Iterate over all possible 3x3 subgrids
        for (int r = 0; r <= rows - 3; ++r) {
            for (int c = 0; c <= cols - 3; ++c) {
                if (isMagicSquare(r, c)) {
                    ++count;
                }
            }
        }

        return count;
    }
};
