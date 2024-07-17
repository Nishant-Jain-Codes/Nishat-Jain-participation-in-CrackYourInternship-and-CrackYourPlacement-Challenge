class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_row_zero = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0)
                        first_row_zero = true;
                    matrix[0][j] = 0;
                    if (i != 0) // so that we wont mark [0][0] as zero since
                                // then it'd be zero'th column = 0
                        matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (matrix[0][0] == 0) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
        if (first_row_zero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};