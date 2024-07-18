// class Solution {
// public:
// // time : exponential 
// // space : O(N^2)
//     bool dfs(vector<vector<char>>& board, int row, int col, int idx,
//                 string& word, vector<vector<bool>>& visited) {
//         if (visited[row][col])
//             return false;
//         if (idx == word.length() - 1)
//             return board[row][col] == word[idx];
//         if (board[row][col] != word[idx])
//             return false;
//         bool possible = false;
//         visited[row][col] = true;
//         if (col - 1 >= 0)
//             possible |= dfs(board, row, col - 1, idx + 1, word, visited);
//         if (col + 1 < board[0].size())
//             possible |= dfs(board, row, col + 1, idx + 1, word, visited);
//         if (row - 1 >= 0)
//             possible |= dfs(board, row - 1, col, idx + 1, word, visited);
//         if (row + 1 < board.size())
//             possible |= dfs(board, row + 1, col, idx + 1, word, visited);
//         visited[row][col] = false;
//         return possible;
//     }
//     bool exist(vector<vector<char>>& board, string word) {
//         for (int i = 0; i < board.size(); i++) {
//             for (int j = 0; j < board[0].size(); j++) {
//                 if (board[i][j] == word[0]) {
//                     vector<vector<bool>> visited(
//                         board.size(), vector<bool>(board[0].size(), false));
//                     if (dfs(board, i, j, 0, word, visited))
//                         return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
//time : O(N*M*L^4)
//space : O(1)
//use the board as visisted hash
    bool dfs(vector<vector<char>>& board, int row, int col, int idx, string& word) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[idx])
            return false;
        if (idx == word.length() - 1)
            return true;
        
        char temp = board[row][col];
        board[row][col] = '#'; // Mark the cell as visited
        
        bool found = dfs(board, row + 1, col, idx + 1, word) ||
                     dfs(board, row - 1, col, idx + 1, word) ||
                     dfs(board, row, col + 1, idx + 1, word) ||
                     dfs(board, row, col - 1, idx + 1, word);
        
        board[row][col] = temp; // Restore the cell's original value
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && dfs(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};
