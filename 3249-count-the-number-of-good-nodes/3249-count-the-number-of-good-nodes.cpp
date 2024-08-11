class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        // Determine the number of nodes (assuming nodes are labeled from 0 to n-1)
        int n = 0;
        for (const auto& edge : edges) {
            n = max(n, max(edge[0], edge[1]));
        }
        n++; // Since nodes are 0-based, we add 1 to get the total number of nodes.

        // Initialize the adjacency list
        vector<vector<int>> adjList(n);

        // Populate the adjacency list
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u); // If the graph is undirected
        }

        vector<int> visited(n, 0);
        int count = 0;

        // DFS to count good nodes
        return dfs(0, adjList, visited).first;

        // return count;
    }

private:
    pair<int,int> dfs(int node, vector<vector<int>>& adjList, vector<int>& visited) {
        visited[node] = 1;
        int maxSize ;
        // bool firs
        bool isGoodNode = true;
        int count=0; 
        int size = 0;
            int i = 0;
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                pair<int,int> ans = dfs(neighbor, adjList, visited);
                if (i!=0 && ans.second != maxSize) {
                    isGoodNode = false;
                }
                i++;
                count+=ans.first;
                maxSize =  ans.second;
                size+=ans.second;
            }
        }

        if (isGoodNode) {
            // cout<<"good node -> "<<node<<endl;
            count++;
        }

        return {count,size+1};
    }
};
