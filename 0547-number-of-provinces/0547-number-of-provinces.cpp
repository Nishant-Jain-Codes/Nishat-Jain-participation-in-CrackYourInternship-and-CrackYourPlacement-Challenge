class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(),0);
        int ans = 0;
        for(int i = 0;i<isConnected.size();i++){
            if(!visited[i]){
                ans++;
                bfs(i,isConnected,visited);
                // dfs(i,isConnected,visited);
            }
        }
        return ans;
    }
private: 
    void bfs(int curV,vector<vector<int>>& graph ,vector<int>& visited){
        queue<int> q;
        q.push(curV);
        visited[curV]=1;
        while(!q.empty()){
            int nowV = q.front();
            q.pop();
            for(int adjV = 0;adjV<graph.size();adjV++){
                if(!visited[adjV] && graph[nowV][adjV]){
                    visited[adjV]=1;
                    q.push(adjV);
                }
            }
        }
    }
    void dfs(int curV,vector<vector<int>>& graph ,vector<int>& visited){
        visited[curV] = 1;
        for(int adjV = 0 ; adjV<graph[0].size();adjV++){
            if(!visited[adjV]&&graph[curV][adjV])
                dfs(adjV,graph,visited);
        }
    }
};