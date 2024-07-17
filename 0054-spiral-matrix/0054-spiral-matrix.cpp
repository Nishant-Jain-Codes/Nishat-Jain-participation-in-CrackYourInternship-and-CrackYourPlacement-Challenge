class Solution {
public:
    // O(N^2) time
    // O(1) extra space
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int totalRow = matrix.size();
        int totalCol = matrix[0].size();
        int startRow = 0;
        int endRow = totalRow - 1;
        int startCol = 0;
        int endCol = totalCol - 1;
        vector<int> ans;
        while(startCol<=endCol && startRow<=endRow){
            //left to right
            for(int col = startCol;col<=endCol;col++){
                ans.push_back(matrix[startRow][col]);
            } 
            startRow++;
            if(startRow>endRow)
                break;
            //top to bottom 
            for(int row = startRow;row<=endRow;row++){
                ans.push_back(matrix[row][endCol]);
            }
            endCol--;
            if(startCol>endCol)
                break;
            //right to left
            for(int col = endCol ; col>=startCol ; col--){
                ans.push_back(matrix[endRow][col]);
            }
            endRow--;
            //bottom to top
            for(int row = endRow; row>=startRow;row--){
                ans.push_back(matrix[row][startCol]);
            }
            startCol++;
            
        }
        return ans;
    }
};