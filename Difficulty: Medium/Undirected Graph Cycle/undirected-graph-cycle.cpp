//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        vector<int> parent(V,-1);
        for(int i = 0;i<V;i++){
            if(!visited[i] &&adj[i].size()>0){
                if(dfs(i,adj,visited,parent))
                    return true;
            }
        }
        return false;
    }
private :   
    bool dfs(int curV , vector<int> adj[] ,vector<int>& visited,vector<int> & parent){
        if(visited[curV])  
            return true;
        visited[curV]=1;
        for(auto &adjV : adj[curV]){
            if(adjV != parent[curV]){
                parent[adjV] = curV;
                if(dfs(adjV,adj,visited,parent))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends