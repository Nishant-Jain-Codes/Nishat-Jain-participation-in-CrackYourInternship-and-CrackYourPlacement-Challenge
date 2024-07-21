class Solution {
public:
    void dfs(vector<vector<char>> & grid , vector<vector<bool>> & visited , int row , int col){
        int m = grid.size();
        int n = grid[0].size();
        if(row>=m || col>=n || row<0 || col<0)
            return;
        if(grid[row][col]=='0' || visited[row][col])
            return ;
        if(grid[row][col]=='1'){
            visited[row][col] = true;
            dfs(grid,visited,row-1,col);
            dfs(grid,visited,row+1,col);
            dfs(grid,visited,row,col-1);
            dfs(grid,visited,row,col+1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int ans = 0;
        for(int i =0;i<m;i++){
            for(int j = 0 ; j<n;j++){
                if(grid[i][j]=='1' && visited[i][j] == false){
                    ans++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return ans;
    }
};