class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        return approach1(grid);
    }
private: 
    // time : O(9*n^2)
    // space : O(9*n^2)
    // approach 1
        //convert each cell of input into a 3x3 grid 
        //'\' matrix with primary diagonal = 1
        // '//' matrix with seconary diagonal = 1
        // ' ' means null matrix 
        // now we'll get a (3n)*(3n) matrix representation of graph 
        // check number of connected components using bfs / dfs 
    int approach1(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> expandedGrid(3*n , vector<int>(3*n,0));
        for(int r = 0;r<n;r++){
            for(int c = 0;c<n;c++){
                if(grid[r][c] == '\\'){
                    expandedGrid[3*r][3*c] = 1;
                    expandedGrid[3*r + 1][3*c + 1] = 1;
                    expandedGrid[3*r + 2][3*c + 2] = 1;
                }
                else if(grid[r][c] == '/'){
                    expandedGrid[3*r][3*c + 2] = 1;
                    expandedGrid[3*r + 1][3*c + 1] = 1;
                    expandedGrid[3*r + 2][3*c] = 1;
                }
                
            }
        }
        queue<pair<int,int>> q ; 
        int m = expandedGrid.size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<m;j++){
                cout<<expandedGrid[i][j]<<" ";
            }
            cout<<endl;
        }
        int parts = 0;
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        for(int i = 0;i<m;i++){
            for(int j = 0;j<m;j++){
                if(expandedGrid[i][j] == 0){
                    parts++;
                    q.push({i,j});
                    expandedGrid[i][j] = 2;
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(auto &dir : directions){
                            int x_new = x + dir.first;
                            int y_new = y + dir.second;
                            if(x_new >= 0 && x_new<m && y_new >= 0 && y_new < m && expandedGrid[x_new][y_new]==0){
                                expandedGrid[x_new][y_new] = 2;
                                q.push({x_new,y_new});
                            }
                        }
                    }
                }
            }
        }
        return parts;
    }
};