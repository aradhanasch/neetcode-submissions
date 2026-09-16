class Solution {
public:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &visited) {
        visited[i] = 1;
        for(auto &it : adj[i]) {
            if(!visited[it]) {
                dfs(it, adj, visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                cnt++;
                dfs(i, adj, visited);
            }
        }
        return cnt;
    }
};
