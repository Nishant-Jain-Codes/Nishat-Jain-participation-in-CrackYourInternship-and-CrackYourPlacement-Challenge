class Solution {
    vector<pair<int,int>> direction;
public:
    Solution(){
        direction = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(!visited[i][j]&&grid[i][j]==1)
                    ans = max(ans,dfs(i,j,visited,grid));
            }
        }
        return ans;
    }
private:
    int dfs(int r ,int c , vector<vector<int>>& visited , vector<vector<int>>& graph){
        visited[r][c] = 1;
        int ans = 1;
        for(auto &[x_,y_]:direction){
            int x = r+x_;
            int y = c+y_;
            if(x>=0 && y>=0 && x<graph.size() && y<graph[0].size() && !visited[x][y] && graph[x][y] == 1){
                ans+= dfs(x,y,visited,graph);
            }
        }
        return ans;
    }
};