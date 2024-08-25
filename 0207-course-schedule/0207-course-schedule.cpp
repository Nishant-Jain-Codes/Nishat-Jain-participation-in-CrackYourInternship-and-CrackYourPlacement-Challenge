class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> hasCycleDP(numCourses,-1);
        for(auto & e : prerequisites){
            adjList[e[0]].push_back(e[1]);
        }
        vector<int> visited(numCourses);
        for(int i = 0 ; i<numCourses;i++){
            if(hasCycle(i,adjList,visited,hasCycleDP))
                return false;
        }
        return true;
    }
    bool hasCycle(int curV , vector<vector<int>>& adjList , vector<int> & visited,vector<int> & hasCycleDP){
        if(visited[curV])
            return true;
        if(hasCycleDP[curV]!=-1)
            return hasCycleDP[curV];
        visited[curV]=1;
        for(auto& adjV : adjList[curV]){
            if(hasCycle(adjV,adjList,visited,hasCycleDP))
                return hasCycleDP[curV]= true;
        }
        visited[curV]=0;
        return hasCycleDP[curV]=false;
    }
};