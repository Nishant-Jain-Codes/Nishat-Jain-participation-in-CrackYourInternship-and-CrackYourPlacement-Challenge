class Solution {
public:
    //Time : O(N^2)
    //Space : O(1)
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        vector<vector<int>> ans;
        int elementsTobeProcessed = rows * cols;
        int maxRightCol = cStart;
        int maxLeftCol = cStart;
        int maxBottomRow = rStart;
        int maxTopRow = rStart;
        while (elementsTobeProcessed) {
            while(cStart<=maxRightCol){
                if (isValidLoc(rows, cols, rStart, cStart)) {
                    ans.push_back({rStart, cStart});
                    elementsTobeProcessed--;
                }
                cStart++;
            }  
            maxRightCol++;
            while(rStart<=maxBottomRow){
                if (isValidLoc(rows, cols, rStart, cStart)) {
                    ans.push_back({rStart, cStart});
                    elementsTobeProcessed--;
                }
                rStart++;
            }
            maxBottomRow++;    
            while (cStart >= maxLeftCol) {
                if (isValidLoc(rows, cols, rStart, cStart)) {
                    ans.push_back({rStart, cStart});
                    elementsTobeProcessed--;
                }
                cStart--;
            }
            maxLeftCol--;
            while (rStart >= maxTopRow) {
                if (isValidLoc(rows, cols, rStart, cStart)) {
                    ans.push_back({rStart, cStart});
                    elementsTobeProcessed--;
                }
                rStart--;
            }
            maxTopRow--;
    }
    return ans;
} 
private : 
    bool isValidLoc(int rows, int cols, int curRow, int curCol) {
        if (curRow >= rows || curCol >= cols || curRow < 0 || curCol < 0)
            return false;
        return true;
    }
}
;