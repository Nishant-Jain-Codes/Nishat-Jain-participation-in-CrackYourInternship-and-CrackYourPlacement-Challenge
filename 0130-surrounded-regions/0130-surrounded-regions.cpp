class Solution {
public:
    //calling dfs on every 0 on the boundary 
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<pair<int,int>> directions ={
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };
        for(int r = 0 ;r<m;r++){
            for(int c=0;c<n;c++ )
                if(r==0||c==0||r==m-1||c==n-1)
                    if(board[r][c] == 'O')
                        dfs(r,c,board,directions);
            
        }
        for(int r = 0 ;r<m;r++){
            for(int c=0;c<n;c++ ){
                if(board[r][c]=='z')
                    board[r][c] = 'O';
                else 
                    board[r][c] = 'X';
            }
        }
    }
private:
    void dfs(int r , int c , vector<vector<char>>&board,vector<pair<int,int>> & directions){
        int m =board.size();
        int n = board[0].size();
        board[r][c] = 'z';
        for(auto & [x_,y_]:directions){
            int x = r+x_;
            int y = c+y_;
            if(x>=0 && y>=0 && x<m&&y<n&&board[x][y]=='O')
                dfs(x,y,board,directions);
        }
    }
};