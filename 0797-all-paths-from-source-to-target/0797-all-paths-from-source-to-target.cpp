class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> allPaths;
        vector<int> curPath ;
        dfs(0,curPath,allPaths,graph);
        return allPaths;
    }
private: 
    void dfs(int curV , vector<int>& curPath , vector<vector<int>> & allPaths , vector<vector<int>> & graph){
        if(curV == graph.size()-1){
            curPath.push_back(curV);
            allPaths.push_back(curPath);
            curPath.pop_back();
            return;
        }
        curPath.push_back(curV);
        for(auto & adjV : graph[curV]){
            dfs(adjV,curPath,allPaths,graph);
        }
        curPath.pop_back();
    }
};