class Solution {
    vector<pair<int,int>> directions;
public:
    Solution(){
        directions = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m =grid.size();
        int n =grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int r=0;r<m;r++){
            if(grid[r][0]==1 && !visited[r][0])
                dfs(r,0,grid,visited);
            if(grid[r][n-1]==1 && !visited[r][n-1])
                dfs(r,n-1,grid,visited);
        }
        for(int c = 0 ; c<n;c++){
            if(grid[0][c]==1 && !visited[0][c])
                dfs(0,c,grid,visited);
            if(grid[m-1][c]==1 && !visited[m-1][c])
                dfs(m-1,c,grid,visited);
        }
        int count = 0;
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                if(grid[i][j] && !visited[i][j])
                    count++;
        return count;
    }
private : 
    void dfs(int r , int c , vector<vector<int>>& grid , vector<vector<int>> & visited){
        visited[r][c] = 1;
        for(auto & [x_,y_] : directions){
            int x = r+x_;
            int y = c+y_;
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && !visited[x][y] && grid[x][y]==1)
                dfs(x,y,grid,visited);
        }
    }
};