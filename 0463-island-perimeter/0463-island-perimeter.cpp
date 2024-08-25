class Solution {
public:
    //bfs 
    //time : O(N*N)
    //space : O(N*N)
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<pair<int,int>> direction ={
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };
        int perimeter = 0;
        queue<pair<int,int>> q;
        for(int i = 0;i<m;i++){
            for(int j = 0 ; j<n;j++){
                if(grid[i][j]==1&&!visited[i][j]){
                    q.push({i,j});
                    visited[i][j] = 1;
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(auto & d : direction){
                            int x_ = x + d.first;
                            int y_ = y + d.second;
                            if(x_<0 || y_<0 || x_>=m || y_>=n ||grid[x_][y_]==0){
                                perimeter++;
                            }
                            else{
                                if(!visited[x_][y_]){
                                    visited[x_][y_] = 1;
                                    q.push({x_,y_});

                                }
                            }
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};