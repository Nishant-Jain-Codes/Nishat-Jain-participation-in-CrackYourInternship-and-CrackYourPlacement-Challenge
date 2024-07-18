class Solution {
public:
    bool helper(vector<vector<char>>& board, int row, int col, int idx,
                string& word, vector<vector<bool>>& visited) {
        if (visited[row][col])
            return false;
        if (idx == word.length() - 1)
            return board[row][col] == word[idx];
        if (board[row][col] != word[idx])
            return false;
        bool possible = false;
        visited[row][col] = true;
        if (col - 1 >= 0)
            possible |= helper(board, row, col - 1, idx + 1, word, visited);
        if (col + 1 < board[0].size())
            possible |= helper(board, row, col + 1, idx + 1, word, visited);
        if (row - 1 >= 0)
            possible |= helper(board, row - 1, col, idx + 1, word, visited);
        if (row + 1 < board.size())
            possible |= helper(board, row + 1, col, idx + 1, word, visited);
        visited[row][col] = false;
        return possible;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> visited(
                        board.size(), vector<bool>(board[0].size(), false));
                    if (helper(board, i, j, 0, word, visited))
                        return true;
                }
            }
        }
        return false;
    }
};