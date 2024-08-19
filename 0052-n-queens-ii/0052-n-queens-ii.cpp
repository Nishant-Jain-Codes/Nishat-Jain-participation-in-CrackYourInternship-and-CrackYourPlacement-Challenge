class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        return dfs(0,board);
    }
private : 
    int dfs(int row , vector<vector<int>> &board){
        if(row == board.size())
            return 1;
        int ways = 0;
        for(int c = 0;c<board[0].size();c++){
            if(isValid(row,c,board)){
                board[row][c] = 1;
                ways+= dfs(row+1,board);
                board[row][c] = 0;
            }
        }
        return ways;
    }
    bool isValid(int r , int c , vector<vector<int>> & board){
        //checking for row validity ( maybe redundant )
        for(int col = 0 ; col<board[0].size();col++){
            if(board[r][col])
                return false;
        }
        //col
        for(int row = 0; row<board.size();row++){
            if(board[row][c])
                return false;
        }
        
        for(int i = r ,j=c;i>=0 && j<board[0].size();i--,j++){
            if(board[i][j])
                return false;
        }
        for(int i = r ,j=c;i>=0 && j>=0;i--,j--){
            if(board[i][j])
                return false;
        }
        for(int i = r ,j=c;i<board.size() && j<board[0].size();i++,j++){
            if(board[i][j])
                return false;
        }
        for(int i = r ,j=c;i<board.size() && j>=0;i++,j--){
            if(board[i][j])
                return false;
        }
        return true;
    }
};