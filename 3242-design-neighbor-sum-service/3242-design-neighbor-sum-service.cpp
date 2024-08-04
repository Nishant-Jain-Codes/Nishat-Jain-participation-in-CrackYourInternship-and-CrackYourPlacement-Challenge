//time : O(1)
//Space : O(1)
class neighborSum {
    vector<vector<int>> grid;
    int rows;
    int cols;
public:
    neighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
        this->rows = grid.size();
        this->cols = grid[0].size();
    }
    bool isValidLoc(int row,int col){
        if(row<0 || col<0 || row>=rows || col>=cols)
            return false;
        return true;
    }
    pair<int,int> findLoc(int value){
        for(int i = 0;i<rows;i++){
            for(int j =0;j<cols;j++){
                if(grid[i][j]==value)
                    return {i,j};
            }
        }
        return {-1,-1};
    }
    int adjacentSum(int value) {
        pair<int,int> loc = findLoc(value);
        int x = loc.first;
        int y = loc.second;
        if(!isValidLoc(x,y))
            return -1;
        int sum = 0;
        sum+=isValidLoc(x,y+1)?grid[x][y+1]:0;
        sum+=isValidLoc(x,y-1)?grid[x][y-1]:0;
        sum+=isValidLoc(x+1,y)?grid[x+1][y]:0;
        sum+=isValidLoc(x-1,y)?grid[x-1][y]:0;
        return sum;
    }
    
    int diagonalSum(int value) {
        pair<int,int> loc = findLoc(value);
        int x = loc.first;
        int y = loc.second;
        if(!isValidLoc(x,y))
            return -1;
        int sum = 0;
        sum+=isValidLoc(x+1,y+1)?grid[x+1][y+1]:0;
        sum+=isValidLoc(x-1,y+1)?grid[x-1][y+1]:0;
        sum+=isValidLoc(x+1,y-1)?grid[x+1][y-1]:0;
        sum+=isValidLoc(x-1,y-1)?grid[x-1][y-1]:0;
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */