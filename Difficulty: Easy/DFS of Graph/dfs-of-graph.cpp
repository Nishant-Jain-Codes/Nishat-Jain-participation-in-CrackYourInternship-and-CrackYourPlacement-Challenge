//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> iterative(int V , vector<int> adj[]){
        
        stack<int> s;
        vector<bool>visited(V,0);
        vector<int> dfs;
        s.push(0);
        visited[0] = true;
        while(!s.empty()){
            int curVertex = s.top();
            s.pop();
            dfs.push_back(curVertex);
            for(int i = adj[curVertex].size()-1 ; i>=0 ; i--){
            // for(int i = 0;i<adj[curVertex].size();i++){
                int adjVertex = adj[curVertex][i];
                if(!visited[adjVertex])
                    {
                        visited[adjVertex] = true;
                        s.push(adjVertex);
                    }
            }
        }
        return dfs;
    }
    void dfs(vector<int> adj[],vector<int> & visited , vector<int> & dfsAns , int curV){
        if(visited[curV])
            return;
        visited[curV] = 1;
        dfsAns.push_back(curV);
        for(auto & x : adj[curV]){
            dfs(adj,visited,dfsAns,x);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> dfsAns;
        vector<int> visited(V,0);
        dfs(adj,visited,dfsAns,0);
        return dfsAns;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends