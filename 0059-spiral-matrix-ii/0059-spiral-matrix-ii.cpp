class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n,-1));
        int r = 0;
        int c = 0;
        int rS = 0;
        int rE = n-1;
        int cS = 0;
        int cE = n-1; 
        int num = 1;
        while(num<=n*n){
            c=cS;
            r=rS;
            while(c<=cE  ){
                mat[r][c] =  num; num++;
                c++;
            }
            rS++;
            c=cE;r=rS;
            while(r<=rE  ){
                mat[r][c] =  num; num++;
                r++;
            }
            cE--;
            c=cE;r=rE;
            while(c>=cS  ){
                mat[r][c] =  num; num++;
                c--;
            }
            rE--;               
            c=cS;r=rE;
            while(r>=rS  ){
                mat[r][c] =  num; num++;
                r--;
            }
            cS++;
        }
        return mat;
  
    }
};