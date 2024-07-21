class Solution {
public:
    //time : O(N^2)
    //space : O(1)
    void rotate(vector<vector<int>>& matrix) {
        //swap along the secondary diagonal  
        //reverse each column
        int n = matrix.size();
        for(int i =0;i<n;i++){
            for(int j = 0 ; j<(n-i) ; j++)
                {
                    swap(matrix[i][j] , matrix[n-1-j][n-1-i]);
                }
        }
        for( int j = 0;j<n;j++){
            for(int i = 0 ; i<n/2;i++){
                swap(matrix[i][j],matrix[n-1-i][j]);
            }
        }
    }
};