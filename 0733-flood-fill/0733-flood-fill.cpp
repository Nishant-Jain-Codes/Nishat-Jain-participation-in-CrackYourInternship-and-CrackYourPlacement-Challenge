class Solution {
public:
    bool isValidLocation(vector<vector<int>>& image,int orignalColor , int row ,int col){
        int m = image.size();
        int n = image[0].size();
        if(row<0 || col<0 || row>=m || col>=n || image[row][col]!=orignalColor)
            return false;
        return true;
    }
    void dfs(vector<vector<int>>& image , int row ,int col , int orignalColor , int targetColor){
        if(!isValidLocation(image,orignalColor,row,col))
            return;
        image[row][col] = targetColor;
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        for(auto &x : directions){
            int newRow = row + x.first;
            int newCol = col + x.second;
            dfs(image, newRow,newCol, orignalColor , targetColor);
        }
    }
    //Time : O(M*N)
    // Space : O(1) + O(N+M) {auxilary stack space}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        if(sr>=m || sc>=n)
            return image;
        if(color == image[sr][sc])
            return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};