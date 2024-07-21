class Solution {
public:
    int alive(vector<vector<int>> & board , int row ,int col){
        int m = board.size();
        int n = board[0].size();
        if(row>= m || row<0 || col>=n || col<0 || board[row][col] == 0 || board[row][col] == -1)
            return 0;
        return 1; 
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i =0;i<m;i++){
            for(int j = 0 ; j<n;j++){
                int aliveNeighbours = 0;
                for(int col = j-1;col<= j+1;col++){
                    aliveNeighbours += alive(board,i-1,col);
                }
                for(int col = j-1;col<= j+1;col++){
                    aliveNeighbours += alive(board,i+1,col);
                }
                aliveNeighbours += alive(board,i,j-1);
                aliveNeighbours += alive(board,i,j+1);
                cout<<aliveNeighbours<<" ";
                if(board[i][j] == 0){
                    if(aliveNeighbours == 3)
                        board[i][j] = -1; // 0 -> 1 in next gen
                }
                else{
                    if(aliveNeighbours < 2)
                        board[i][j] = -2; // 1 -> 0 in next gen
                    else if(aliveNeighbours > 3)
                        board[i][j] = -2; // 1-> 0 in next gen
                }
            }
                cout<<endl;
        }
        for(int i =0;i<m;i++){
            for(int j = 0 ; j<n;j++){
                if(board[i][j] == -1)
                    board[i][j] = 1;
                if(board[i][j] == -2)  
                    board[i][j] = 0;
            }
        }
    }
};