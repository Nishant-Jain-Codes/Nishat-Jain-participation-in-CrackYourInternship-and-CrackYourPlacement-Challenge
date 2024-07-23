//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<pair<char,pair<int,int>>> directions = { {'U',{-1,0}},{'D',{1,0}},{'R',{0,1}},{'L',{0,-1}}};
    bool isValidLocation(vector<vector<int>> & mat , int row , int col){
        int n = mat.size();
        if(row>=n || col>=n || row<0 || col<0 || mat[row][col]!=1 )
            return false;
        return true;
    }
    void dfs(vector<vector<int>> & mat , int row ,int col ,string & curPath,vector<string>& allPaths){
        int n = mat.size();
        if (row == n - 1 && col == n - 1 && mat[row][col] == 1) {
            string newPath (curPath);
            // cout<<newPath<<" "<<curPath;
            allPaths.push_back(newPath);
            return ;
        }
        if(!isValidLocation(mat,row,col))
            return;
        //mark visited
        mat[row][col] = -1;
        for(int i = 0 ; i<4 ;i++){
            // vector<pair<char,pair<int,int>>> curMove = directions[i];
            // char path_val = curMove.first;
            // pair<int,int> coord = curMove.second;
            // int x = coord.first;
            // int y = coord.second;
             char path_val = directions[i].first;
            int x = directions[i].second.first;
            int y = directions[i].second.second;
            curPath.push_back(path_val);
            dfs(mat,row+x,col+y,curPath,allPaths);
            curPath.pop_back();
        }
        mat[row][col] = 1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string> allPaths;
        string curPath="";
        if(mat[0][0])
            dfs(mat,0,0,curPath,allPaths);
        // cout<<allPaths.size()<<endl;
        return allPaths;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends