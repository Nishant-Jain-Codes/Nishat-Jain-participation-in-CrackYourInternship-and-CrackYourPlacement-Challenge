class Solution {
public:
    //time complexity : O(N!) 
    //space compelxity : O(N) ( auxilary stack space)
    void addBoard(vector<string>& board, vector<vector<string>> & output){
        vector<string> newBoard(board);
        output.push_back(newBoard);
    }
    bool isValid(vector<string>& board,int row, int col){
        //check vertical space
        for(int curRow = row-1 ; curRow >= 0 ; curRow--)
            {
                if(board[curRow][col]=='Q')
                    return false;
            }
        //check primiary diagonal 
        for(int curCol = col-1 , curRow = row-1;curCol>=0 && curRow>=0 ; curCol--,curRow-- ){
            if(board[curRow][curCol]=='Q')
                return false;
        }
        //check secondary diagonal 
        for(int curCol = col+1 , curRow = row-1;curCol<=board[0].length() && curRow>=0 ; curCol++,curRow-- ){
            if(board[curRow][curCol]=='Q')
                return false;
        }
        return true;
    }
    void fillBoard(vector<string> & board , int curRow , vector<vector<string>> & output){
        if(curRow == board.size())
            {
                addBoard(board,output);
                return ;
            }
        for(int curCol = 0;curCol<board[0].length();curCol++){
            if(isValid(board,curRow,curCol)){
                board[curRow][curCol] = 'Q';
                fillBoard(board,curRow+1,output);
                board[curRow][curCol] = '.'; // back track
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output ;
        //create template 
        vector<string> board;
        for(int i = 0 ;i <n;i++){
            string row = "";
            for(int j = 0;j<n;j++){
                row.push_back('.');
            }
            board.push_back(row);
        }
        for(auto x : board){
            cout<<x<<endl;
        }
        // call helper function (template ,curRow , output)
        fillBoard(board,0,output);
        return output;
    }
};