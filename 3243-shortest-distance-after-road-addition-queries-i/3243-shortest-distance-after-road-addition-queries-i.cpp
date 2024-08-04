class Solution {
public:
    int bfs(vector<vector<int>> & adjList,int n){
        queue<pair<int,int>> q;
        unordered_set<int> visited;
        q.push({0,0});
        visited.insert(0);
        while(!q.empty()){
            int curV = q.front().first;
            int curD = q.front().second;
            // cout<<curV<<":"<<curD<<",";
            q.pop();
            if (curV==n-1)
                return curD;
            for(auto &adjV : adjList[curV]){
                if(visited.find(adjV)==visited.end())
                    {
                        // cout<<adjV<<" "<<curD<<endl;
                        visited.insert(adjV);
                        // cout<<"curD + 1 -> "<<curD+1<<endl;
                        q.push({adjV,curD+1});
                    }
            }
        }
        cout<<endl;
        return -1;
    }
    //time : O(Q* (V+E))
    //space : O(V+E)
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        //initial condition
        vector<int> answer;
        vector<vector<int>> adjList(n); 
        for(int i =0;i<n-1;i++){
            adjList[i].push_back(i+1);
        }
        //apply bfs after every query
        for(auto &query : queries){
            // cout<<query[0]<<" "<<query[1]<<endl;
            adjList[query[0]].push_back(query[1]);
            answer.push_back(bfs(adjList,n));
        }
        return answer;
    }
};