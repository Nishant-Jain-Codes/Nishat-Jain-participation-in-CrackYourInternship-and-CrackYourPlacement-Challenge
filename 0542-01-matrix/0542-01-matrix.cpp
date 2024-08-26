class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    //push every 0's location in the queue 
    return approach1(mat);    
    }
private: 
    //time : O(N*N)
    //space : O(N*N)
    vector<vector<int>> approach1(vector<vector<int>> & mat){
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> minDist(m,vector<int>(n,0));
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<vector<int>> q;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j]==0)
                    {
                        q.push({i,j,0});
                        visited[i][j] = 1;
                    }
            }
        }
        vector<pair<int,int>> dir = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };
        while(!q.empty()){
            int x = q.front()[0];
            int y = q.front()[1];
            int d = q.front()[2];
            minDist[x][y] = d;
            q.pop();
            for(auto &[x_,y_] : dir){
                int newX = x_ + x;
                int newY = y_ + y;
                if(newX>=0 && newY>=0 && newX<m && newY < n && !visited[newX][newY]){
                    visited[newX][newY] = 1;
                    q.push({newX,newY,d+1});
                }
            }
        }
        return minDist;
    }
};