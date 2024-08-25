class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // return bfs(isConnected);
        vector<int> visited(isConnected.size(),0);
        int ans = 0;
        for(int i = 0;i<isConnected.size();i++){
            if(!visited[i]){
                ans++;
                dfs(i,isConnected,visited);
            }
        }
        return ans;
    }
private: 
    void dfs(int curV,vector<vector<int>>& graph ,vector<int>& visited){
        visited[curV] = 1;
        for(int adjV = 0 ; adjV<graph[0].size();adjV++){
            if(!visited[adjV]&&graph[curV][adjV])
                dfs(adjV,graph,visited);
        }
    }
};