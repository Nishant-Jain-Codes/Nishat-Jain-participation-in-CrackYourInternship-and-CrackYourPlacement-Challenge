class Solution {
public:
    // time : O(M*N)
    // space : O(M+N)
    // 1st dfs traversal mark all traverced cell as 0 
    // 2nd dfs traversal if path found ans is false , since by putting 0 in previous traveral we blocked all common paths , but if a path still exists that means that there is no single point of failure in our network
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if(!dfs(grid,0,0))
            return true;
        grid[0][0] = 1;
        return !dfs(grid,0,0);
    }
private: 
    bool dfs(vector<vector<int>> & grid , int r , int c ){
        if(r<0 || c<0 || r>= grid.size() || c>= grid[0].size() || grid[r][c]!=1)
            return false;
        if(r==grid.size()-1 && c == grid[0].size()-1)
            return true;
        grid[r][c] = 0;
        return dfs(grid,r+1,c)||dfs(grid,r,c+1);
    }
};