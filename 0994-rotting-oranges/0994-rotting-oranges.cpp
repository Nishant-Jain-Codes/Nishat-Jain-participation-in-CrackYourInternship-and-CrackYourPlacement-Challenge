class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> minTime(m,vector<int>(n,INT_MAX));
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<vector<int>> q;
        for(int i = 0;i<m;i++){
            for(int j = 0 ; j<n;j++){
                if(grid[i][j]==2 )
                    {
                        q.push({i,j,0});
                        visited[i][j]=1;
                    }

            }
        }
        int ans = 0;
        
                    while(!q.empty()){
                        int x = q.front()[0];
                        int y = q.front()[1];
                        int t = q.front()[2];
                        q.pop();
                        ans = max(ans,t);
                        for(auto & d : dir){
                            int x_ = x + d.first;
                            int y_ = y + d.second;
                            if(x_>=0 && y_>=0 && x_<m && y_<n && !visited[x_][y_] && grid[x_][y_]==1){
                                visited[x_][y_] = 1;
                                q.push({x_,y_,t+1});
                            }
                        }
                    }
                
            
        
        for(int i = 0;i<m;i++){
            for(int j = 0 ; j<n;j++){
                if(grid[i][j]==1 )
                    if(!visited[i][j])
                        return -1;
                    // else 
                        // ans = max(minTime[i][j],ans);
            }
        }
        return ans;
    }   
};